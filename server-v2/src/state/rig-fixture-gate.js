/**
 * THE RIG / PRODUCTION BOUNDARY, made mechanical.
 *
 * V2 is developed against one Raspberry Pi and one emulator on a private LAN, so
 * the directory necessarily carries values that exist only to make that rig
 * work: a private-network host literal, placeholder record keys, a zero player cap.
 * Every one of them is recorded in `docs/PROTOCOL-VALUE-INVENTORY.md`.
 *
 * The failure this guards against is not using those values - that is correct
 * and deliberate today - but SHIPPING them while believing the configuration is
 * production. Review cannot be the control: this project has repeatedly proved
 * that a value nobody re-read is a value nobody noticed.
 *
 * So a directory that declares `provenance: "operator"` is checked here and
 * REFUSED if it still looks like the rig. A `test-fixture` directory is exempt,
 * because it has already declared what it is and production refuses it anyway.
 *
 * ## What this does NOT mean
 *
 * Passing is not a certificate of production readiness. It only means no KNOWN
 * rig marker is present. Every "Temporary (RIG)" row and every UNKNOWN field
 * meaning in the inventory must still be closed by hand.
 */

import { DIRECTORY_PROVENANCE } from './directory-state.js';

export class RigFixtureError extends Error {
  constructor(code, message, findings) {
    super(message);
    this.name = 'RigFixtureError';
    this.code = code;
    this.findings = findings;
  }
}

/**
 * Private and loopback ranges. A production server reachable only from a private
 * network cannot serve real players, so a private literal is decisive evidence
 * that a rig value survived.
 */
function isPrivateOrLoopbackAddress(text) {
  const octets = /^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$/.exec(text.trim());
  if (octets == null) return false;
  const [a, b] = [Number(octets[1]), Number(octets[2])];
  if (a === 127 || a === 0) return true;
  if (a === 10) return true;
  if (a === 192 && b === 168) return true;
  if (a === 172 && b >= 16 && b <= 31) return true;
  if (a === 169 && b === 254) return true;
  return false;
}

/**
 * Placeholders this project has actually shipped, so the list is evidence rather
 * than imagination. `SLOT0001` and `PAL Lobby` are V1's; the rest are V2's own
 * example directory.
 */
const PLACEHOLDER_PATTERNS = [
  /^PAL-V2-/i,
  /^E\d+R\d+$/i,
  /^RECORD-/i,
  /^F\d+$/i,
  /^SLOT\d+$/i,
  /^PAL Lobby$/i,
  /^Test Slot$/i,
  /^OPEN$/i
];

function asText(field) {
  return Buffer.isBuffer(field) ? field.toString('latin1') : String(field ?? '');
}

function checkPlaceholder(findings, label, field) {
  const text = asText(field);
  if (text.length === 0) return;
  if (PLACEHOLDER_PATTERNS.some((pattern) => pattern.test(text))) {
    findings.push(`${label} is the placeholder ${JSON.stringify(text)}`);
  }
}

/**
 * Refuse an operator-provenance directory that still carries rig-only values.
 *
 * @param {object} directory a constructed DirectoryState
 * @param {object} [options]
 * @param {boolean} [options.enforce] when false, return findings without throwing
 * @returns {string[]} the findings (empty when clean)
 */
export function assertNoRigFixtureValues(directory, { enforce = true } = {}) {
  const findings = [];
  // A directory that admits to being a fixture is not lying about itself, and
  // production already refuses it on provenance alone.
  if (directory.provenance !== DIRECTORY_PROVENANCE.OPERATOR) return findings;

  if (directory.entryCount === 0) {
    // The client treats a 0x6503 declaring zero entries as terminal.
    findings.push('the directory declares zero entries, which is a terminal client error');
  }

  for (let index = 0; index < directory.entryCount; index += 1) {
    const entry = directory.entryAt(index);
    const label = `entry ${entry.entryId}`;

    const host = asText(entry.host);
    if (isPrivateOrLoopbackAddress(host)) {
      findings.push(
        `${label} host ${JSON.stringify(host)} is a private or loopback address; ` +
        'it is a rig fixture and cannot serve real players'
      );
    }
    checkPlaceholder(findings, `${label} host`, entry.host);
    checkPlaceholder(findings, `${label} name`, entry.name);
    checkPlaceholder(findings, `${label} description`, entry.description);
    checkPlaceholder(findings, `${label} pageField`, entry.pageField);

    // The 8 raw entry bytes have NO decoded meaning (inventory 2.4). Zero is the
    // least-assertive value; anything else is asserting something we cannot read.
    if (Buffer.isBuffer(entry.raw8) && entry.raw8.some((byte) => byte !== 0)) {
      findings.push(
        `${label} raw8 is non-zero, but those 8 bytes have no decoded meaning; ` +
        'shipping a guess there is exactly the habit this gate exists to stop'
      );
    }

    for (const record of entry.records) {
      const recordLabel = `${label} record ${record.recordId}`;
      checkPlaceholder(findings, `${recordLabel} unknownField0`, record.unknownField0);
      checkPlaceholder(findings, `${recordLabel} unknownField1`, record.unknownField1);
      checkPlaceholder(findings, `${recordLabel} unknownField2`, record.unknownField2);
      // The client reads population >= max as "Server full. You cannot
      // participate." (FUN_005bc990, status 0xd), so zero is not neutral here.
      if (record.unknownWord1 === 0) {
        findings.push(
          `${recordLabel} maximum players is 0; the client reads that as permanently full`
        );
      }
    }
  }

  if (enforce && findings.length > 0) {
    throw new RigFixtureError(
      'RIG_FIXTURE_IN_PRODUCTION',
      'this directory claims operator provenance but still carries rig-only values:\n' +
      findings.map((finding) => `  - ${finding}`).join('\n') +
      '\nSee docs/PROTOCOL-VALUE-INVENTORY.md. Passing this gate is NOT production readiness.',
      findings
    );
  }
  return findings;
}
