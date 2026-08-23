/**
 * One source of truth for the two account names. They are DIFFERENT things and
 * they have different limits; conflating them is what produced the defect this
 * module exists to prevent.
 *
 * loginIdentity  - the persistent account and authentication identifier. This is
 *                  the value the client carries in the UDP-9090 register
 *                  `handle` field and in `<loginIdentity>@cee-auth`, and it is
 *                  the key the register uses to find the account whose password
 *                  is the Blowfish key. Stored in the `accounts.userid` column.
 *
 * displayName    - the roster display name the server places in member records.
 *                  Never sent to the client over HTTP, never stored on the
 *                  memory card, and not part of authentication. Stored in the
 *                  `accounts.handle` column, whose name predates this
 *                  distinction and is kept to avoid a pointless schema change.
 *
 * Why the login identity is capped at 10 BYTES
 * -------------------------------------------
 * The client's account-creation path copies the identity out of the server's
 * HTML with a fixed-width `strncpy(dst, cursor + 12, 10)` followed by
 * `dst[10] = 0` (overlay netwk, `0x005e74ac`-`0x005e7500`; see
 * `docs/findings/protocol/HANDLE-MODEL-RE-2026-08-03.md` section 3). An
 * 11-character identity would be silently truncated to 10 in `0x870870`,
 * written truncated to the memory card, and registered truncated - so the
 * register's account lookup would miss, and because the register reply's
 * Blowfish key is that account's password, the failure would surface as a
 * crypto fault rather than as a bad username.
 *
 * We reject rather than truncate. Truncating would make two distinct accounts
 * collide on the wire.
 *
 * Bytes, not characters
 * ---------------------
 * Every limit here is a BYTE limit, measured explicitly, because the client
 * copies raw bytes and its own marker table contains Shift-JIS strings - so
 * "one character is one byte" is not a safe assumption anywhere near this
 * client. Both names are additionally restricted to ASCII: for the login
 * identity because it must round-trip byte-exactly through HTML, the memory
 * card and the register, and for the display name because the encoding the
 * client expects in a roster record is UNPROVEN. See OQ-021.
 */

/** Fixed-width client copy: `strncpy(dst, src, 10); dst[10] = 0`. */
export const LOGIN_IDENTITY_MAX_BYTES = 10;
export const LOGIN_IDENTITY_MIN_BYTES = 3;

/**
 * The roster member record's name field is 16 bytes NUL-padded (op06 record
 * `+0x00`, `memcpy(..., 0x10)`), so 15 bytes are usable with a terminator.
 * Not yet exercised on the wire - no display name has ever differed from a
 * login identity.
 */
export const DISPLAY_NAME_MAX_BYTES = 15;
export const DISPLAY_NAME_MIN_BYTES = 3;

export const PASSWORD_MIN_BYTES = 4;
export const PASSWORD_MAX_BYTES = 14;

const LOGIN_IDENTITY_CHARSET = /^[A-Za-z0-9_]+$/;
/** Printable ASCII excluding space - matches what the soft keyboard can emit. */
const PASSWORD_CHARSET = /^[\x21-\x7e]+$/;
/** Printable ASCII including space; a roster name may legitimately contain one. */
const DISPLAY_NAME_CHARSET = /^[\x20-\x7e]+$/;

/**
 * Byte length of a string as it would be written to the wire. `latin1` maps one
 * code unit to one byte, so any character above U+00FF is already excluded by
 * the ASCII charset checks; this measures what the charset check allows.
 */
export function byteLength(value) {
  return Buffer.byteLength(value, 'latin1');
}

function isAscii(value) {
  for (let index = 0; index < value.length; index += 1) {
    if (value.charCodeAt(index) > 0x7f) return false;
  }
  return true;
}

/**
 * @returns {null | {code: string, message: string}} null when acceptable.
 */
export function checkLoginIdentity(value, field = 'userid') {
  const normalized = String(value ?? '');
  if (!isAscii(normalized) || !LOGIN_IDENTITY_CHARSET.test(normalized)) {
    return {
      code: 'INVALID_USERID',
      message: `${field} must contain only ASCII letters, digits, or underscores`
    };
  }
  const bytes = byteLength(normalized);
  if (bytes < LOGIN_IDENTITY_MIN_BYTES || bytes > LOGIN_IDENTITY_MAX_BYTES) {
    return {
      code: 'INVALID_USERID',
      message:
        `${field} must be ${LOGIN_IDENTITY_MIN_BYTES}-${LOGIN_IDENTITY_MAX_BYTES} bytes ` +
        `(the client truncates a longer one to ${LOGIN_IDENTITY_MAX_BYTES})`
    };
  }
  return null;
}

export function checkDisplayName(value, field = 'displayName') {
  const normalized = String(value ?? '');
  if (!isAscii(normalized) || !DISPLAY_NAME_CHARSET.test(normalized)) {
    return {
      code: 'INVALID_DISPLAY_NAME',
      message: `${field} must contain only printable ASCII`
    };
  }
  const bytes = byteLength(normalized);
  if (bytes < DISPLAY_NAME_MIN_BYTES || bytes > DISPLAY_NAME_MAX_BYTES) {
    return {
      code: 'INVALID_DISPLAY_NAME',
      message: `${field} must be ${DISPLAY_NAME_MIN_BYTES}-${DISPLAY_NAME_MAX_BYTES} bytes`
    };
  }
  // Both roster fillers strip a trailing '-', so a name ending in one would not
  // round-trip. See HANDLE-MODEL-RE-2026-08-03.md section 1.
  if (normalized.endsWith('-')) {
    return {
      code: 'INVALID_DISPLAY_NAME',
      message: `${field} must not end with '-'; the client strips a trailing dash`
    };
  }
  return null;
}

export function checkPassword(value, field = 'password') {
  const normalized = String(value ?? '');
  if (!isAscii(normalized) || !PASSWORD_CHARSET.test(normalized)) {
    return {
      code: 'INVALID_PASSWORD',
      message: `${field} must contain only printable ASCII without spaces`
    };
  }
  const bytes = byteLength(normalized);
  if (bytes < PASSWORD_MIN_BYTES || bytes > PASSWORD_MAX_BYTES) {
    return {
      code: 'INVALID_PASSWORD',
      message: `${field} must be ${PASSWORD_MIN_BYTES}-${PASSWORD_MAX_BYTES} bytes`
    };
  }
  return null;
}
