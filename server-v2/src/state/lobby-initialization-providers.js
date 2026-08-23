import { DirectoryState, StaticDirectoryProvider } from './directory-state.js';
import { createClientDirectoryProjection } from './client-directory-projection.js';

/**
 * The four TCP 10127 providers, backed by directory state instead of fixtures.
 *
 * Providers are per connection because the state they read is per connection:
 * traversal position, resident records and the field codec word all belong to
 * one client. `createConnectionProviders` is therefore called once per lobby
 * connection, and the projection it builds is dropped when that connection
 * closes. Authoritative directory state is shared and never mutated here.
 *
 * ## Which mode `0x6501` answers: 1, on BOTH connections
 *
 * **Observation** (`FUN_001c6e80`, corpus decompile, re-read 2026-08-06):
 *
 * | reply mode | connection state word | client phase |
 * |---|---|---|
 * | 1 | any | 6 -> `0x6503`, and `0x365e1a = 8`, cursors zeroed |
 * | 0 | 5 | `0x0c` -> `0x6510` directly |
 * | 0 | anything else | 8 -> `0x6502` |
 * | anything else | any | terminal error |
 *
 * The mode SELECTS the route; it is not a capability flag. `0x6503` is the only
 * command that writes the client's entry table at `0x365e20` and its total at
 * `0x365e1e`, so a client that never sees mode 1 renders Server Select with a
 * zero count and an unfilled row - the fill loop is `for i < count` (T32).
 *
 * T32 shipped this CONDITIONAL - mode 1 only on the connection that presented
 * `0x1007` - on the inference that a `0x6501`-first connection is state 5 and
 * must take the mode-0 route. **The wire refutes it.**
 * `2026_07_30_14_52_53_snap_session6_trace.log` is a `0x6501`-first V1
 * connection: line 17 answers `01 00000000 00000000`, mode 1, and line 22 is the
 * client's `0x6503` request. Wire outranks inference, so the mode is now
 * unconditional. This is gap-table correction C-1.
 *
 * `resumed` is still reported and still used - not to choose the mode, but
 * because a resumed connection given mode 1 RE-WALKS its whole directory, and
 * the projection has to be at the start of a walk for that. See
 * `takeCommand6503Batch`, which rewinds on the client's own re-walk signal.
 *
 * The request's BE32 is passed through to the caller untouched. Whether it
 * constrains the server's mode choice is Unknown, so nothing is inferred from it.
 */

/**
 * The two BE32 values the mode-1 `0x6501` reply carries.
 *
 * Neither is validated by the client, but the FIRST is acted on, so it is not
 * a free value. Zero is chosen as the least-assertive setting, which is a
 * weaker and more honest claim than calling it Implementation Control:
 *
 * - the first lands in `0x365e04`. `FUN_005c7900` (overlay `3.DAT`) returns
 *   early while its countdown `0x86f838` is above zero and loads `0x365e04`
 *   into that countdown when a fetch STARTS, and `FUN_006233e0` decrements it
 *   per tick - so it is a COOLDOWN BETWEEN fetches, not a one-off skip. Zero
 *   means no cooldown. **Inferred**, and one rank below main-ELF evidence:
 *   `FUN_005c7900` is an overlay function and the corpus records it as
 *   runtime-unvalidated. `docs/PROTOCOL-VALUE-INVENTORY.md` row 4.2 carries
 *   the same grade; keep the two in step.
 * - the second lands in `0x365e00` and is echoed back verbatim in the next
 *   `0x6501` request (`FUN_001c3ea0(ctx, 0x365e00)`), which is its only known
 *   reader. An opaque server cookie; zero claims nothing.
 *
 * They are constants rather than directory fields on purpose: making them
 * operator-configurable would invite choosing a non-zero cooldown whose
 * consequences have never been observed.
 */
export const COMMAND_6501_MODE1_REFETCH_SUPPRESSION_TICKS = 0;
export const COMMAND_6501_MODE1_COOKIE = 0;

/**
 * The field codec word a lobby-initialization connection holds.
 *
 * `+0x4c` is written only by `FUN_001c4100`, the handler the ELF tables bind to
 * command `0x1002` direction `0x01` - a server-sent frame that this connection
 * never carries. All four captured `0x1007` identity fields decode and checksum
 * with zero and with nothing else, so zero is what the client is holding. The
 * same word verifies the server's own fields, so encoding with anything else
 * would make `FUN_001c3b90` return -3.
 *
 * This is a connection property, not a per-response choice. It is deliberately
 * not exposed as something a caller can vary per command.
 */
export const LOBBY_CONNECTION_CODEC_BYTE = 0;

/**
 * The `0x6501` mode policy, in ONE place.
 *
 * Both the standalone providers and the composed application answer `0x6501`,
 * and a mode chosen independently in two files is a divergence waiting to
 * happen - so both call this. `resumed` is the transport's report of whether
 * this connection presented `0x1007`; it is still required rather than
 * defaulted, so that a caller cannot omit the entry path and then be surprised
 * when a later policy needs it.
 *
 * The answer is mode 1 either way - V1 answered mode 1 on its `0x6501`-first
 * connection and the client duly asked for `0x6503` (session 6, lines 17 and
 * 22). See the header for the correction this replaces.
 */
export function selectCommand6501Mode({ resumed }) {
  if (typeof resumed !== 'boolean') {
    throw new TypeError('selectCommand6501Mode requires the connection entry path as a boolean');
  }
  return {
    mode: 1,
    unknown0: COMMAND_6501_MODE1_REFETCH_SUPPRESSION_TICKS,
    unknown1: COMMAND_6501_MODE1_COOKIE
  };
}

export function createDirectoryBackedProviders({
  directoryProvider,
  codecByte,
  /**
   * The LIVE current-player count for one directory entry, or null to keep
   * publishing the static configured value.
   *
   * `({ entry, record, entryIndex, recordId }) => number`
   *
   * This is the Server Select "Current players" field. Without it the projection
   * falls back to `record.unknownWord6510`, a configuration constant with no
   * runtime input - it reads 0 with one player signed in and it would read 0 with
   * fifty, which is exactly what the rig showed.
   *
   * Passed in rather than reached for: this module knows the directory and the
   * wire format, and deliberately not who is connected. The caller owns presence.
   */
  resolveCurrentPlayers = null
} = {}) {
  if (directoryProvider == null || typeof directoryProvider.currentDirectory !== 'function') {
    throw new TypeError('createDirectoryBackedProviders requires a directory provider');
  }
  if (resolveCurrentPlayers !== null && typeof resolveCurrentPlayers !== 'function') {
    throw new TypeError('resolveCurrentPlayers must be a function when supplied');
  }
  const connectionCodecByte = codecByte ?? LOBBY_CONNECTION_CODEC_BYTE;
  if (!Number.isSafeInteger(connectionCodecByte) ||
      connectionCodecByte < 0 || connectionCodecByte > 0xff) {
    throw new TypeError('codecByte must be an unsigned byte');
  }

  const openProjections = new Set();

  /**
   * Build a projection. Called ONCE per logical lobby session, not per
   * connection: the client retains its directory state across a transport reset
   * and afterwards sends `0x6510` as a targeted fetch for a key issued on the
   * previous connection. See `src/sessions/lobby-session.js`.
   */
  function createProjection() {
    const directory = directoryProvider.currentDirectory();
    if (!(directory instanceof DirectoryState)) {
      throw new TypeError('directory provider did not return a DirectoryState');
    }
    if (directory.entryCount === 0) {
      throw new Error('refusing to serve a lobby connection from an empty directory');
    }
    const projection = createClientDirectoryProjection({
      directory,
      codecByte: connectionCodecByte,
      /*
       * Resolved at ANSWER time, never snapshotted at `0x6504`-delivery. The
       * count is a query over who is connected right now; capturing it by value
       * would make it stale by several round trips even once it was live.
       */
      resolveRecordWord: resolveCurrentPlayers === null
        ? null
        : (context) => {
          const live = resolveCurrentPlayers(context);
          if (!Number.isSafeInteger(live) || live < 0) {
            throw new TypeError(
              `resolveCurrentPlayers returned ${live} for record ${context.recordId}; ` +
              'the 0x6510 current-players field is a count'
            );
          }
          // The field is a BE16 and the projection refuses anything wider, so a
          // real server that somehow exceeded it should publish a saturated
          // count rather than fail the whole lobby ladder over a display value.
          return Math.min(live, 0xffff);
        }
    });
    openProjections.add(projection);
    return projection;
  }

  /**
   * Providers bound to an EXISTING projection. A resume passes the projection
   * its session already owns; nothing is created, cloned or rebuilt here.
   */
  function createProvidersForProjection(projection) {
    return {
      projection,
      resolveCommand6501Response: ({ resumed }) => selectCommand6501Mode({ resumed }),
      resolveCommand6503Response: ({ requestedStart, requestedCount }) =>
        projection.takeCommand6503Batch({ start: requestedStart, count: requestedCount }),
      resolveCommand6502Response: () => projection.selectCommand6502Response(),
      resolveCommand6504Response: ({ sequence }) =>
        projection.takeCommand6504Batch({ sequence }),
      resolveCommand6510Response: ({ sequence, unknownEncodedRecordFields }) =>
        projection.resolveCommand6510Response({
          sequence,
          encodedRecordFields: unknownEncodedRecordFields
        }),
      close: () => {
        // The TRANSPORT is done with the projection; the SESSION may not be.
        // Releasing it is the session's decision, via releaseProjection().
      }
    };
  }

  /**
   * Providers that OWN the projection they create, released on close.
   *
   * This is the standalone path, used where there is no lobby session to hold
   * the projection - the wire-boundary tests, and any embedder driving the
   * ladder directly. The composed application does NOT use it: there the
   * projection belongs to the lobby session and survives the transport, because
   * the client keeps its directory state across a reset.
   */
  function createConnectionProviders() {
    const projection = createProjection();
    const providers = createProvidersForProjection(projection);
    return {
      ...providers,
      close: () => {
        releaseProjection(projection);
      }
    };
  }

  function releaseProjection(projection) {
    return openProjections.delete(projection);
  }

  return {
    createConnectionProviders,
    createProjection,
    createProvidersForProjection,
    releaseProjection,
    /** Open projections, for tests and health reporting. Never protocol input. */
    openConnectionCount: () => openProjections.size
  };
}

export { StaticDirectoryProvider };
