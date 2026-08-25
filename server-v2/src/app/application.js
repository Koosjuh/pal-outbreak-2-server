import fs from 'node:fs';

import { createDnsService } from '../dns/dns-service.js';
import { createConfiguredDnasService } from '../dnas/dnas-service.js';
import { createWebService } from '../http/web-service.js';
import { createTcp10127Service } from '../tcp/tcp10127-service.js';
import { Tcp10127CreateConfigDialogue } from '../tcp/create-config-dialogue.js';
import { Tcp10127LobbyButtonsDialogue } from '../tcp/lobby-buttons-dialogue.js';
import { createV1ObservedAreaTable } from '../state/area-table-v1.js';
import { createTimingWheel } from '../transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../udp/area-directory.js';
import { SnapRegisterService } from '../udp/register-service.js';
import { SnapLobbySessions } from '../udp/snap-lobby-sessions.js';
import { openProductionRepositories } from '../database/production-repositories.js';
import { ConnectionIdentityRegistry } from '../sessions/connection-identity.js';
import {
  ACCOUNT_PROOF,
  AccountSessionError,
  AccountSessionRegistry
} from '../sessions/account-session.js';
import { LobbySession } from '../sessions/lobby-session.js';

/** How often idle account sessions are swept, independent of traffic. */
const CLEANUP_INTERVAL_MS = 15 * 1000;
import { LobbyArmingRegistry } from '../sessions/lobby-arming.js';
import { DIRECTORY_PROVENANCE } from '../state/directory-state.js';
import { LobbyRoomRegistry } from '../state/lobby-rooms.js';
import { PresenceRegistry } from '../state/presence.js';
import { PublishableDirectoryProvider, loadDirectoryFile } from '../state/directory-source.js';
import { assertNoRigFixtureValues } from '../state/rig-fixture-gate.js';
import {
  createDirectoryBackedProviders,
  selectCommand6501Mode
} from '../state/lobby-initialization-providers.js';

/**
 * The composed V2 server: DNS, DNAS, HTTP and the TCP lobby service in one
 * process, over one validated configuration, one authoritative directory and one
 * identity registry.
 *
 * Startup is ordered and fail-fast. Everything that can be validated without a
 * socket - configuration, the master key, the directory document - is validated
 * first, then listeners bind in a fixed order. If any required listener fails to
 * bind, every listener already up is closed again and the error propagates, so
 * the process either serves all of its endpoints or none of them. A partially
 * bound server is the worst outcome available: the client would reach DNS,
 * follow it here, and then fail at a port that never opened.
 *
 * Shutdown reverses that order and closes the database last.
 */

/**
 * Connection purpose on TCP 10127.
 *
 * Superseded the T19 heuristic after the first real-client run (T20). That
 * heuristic assumed purpose could follow the first client frame; the client
 * sends no first frame, because the SERVER speaks first on this port. A
 * hardcoded `lobby-initialization` therefore left both sides waiting until the
 * idle timeout, and the client reported D907.
 *
 * The real rule, from the captures and from V1's known-good implementation
 * (`server/snap_server.js:1657-1697`): a connection that no completed
 * `POST /mhweb/lbs.jsp` has armed is a BOOT AUTH connection and receives the
 * `0x1001`/`0x1002`/`0x1004` transcript; an armed one is a LOBBY connection and
 * receives the `0x6001` challenge. See `src/sessions/lobby-arming.js` for why
 * keying that on the remote address is safe here and is not identity.
 */

function closeHttpLike(server) {
  return new Promise((resolve) => {
    if (server == null) return resolve();
    let settled = false;
    const finish = () => {
      if (settled) return;
      settled = true;
      resolve();
    };
    server.close(finish);
    // A client that keeps a socket open must not be able to block shutdown.
    if (typeof server.closeAllConnections === 'function') {
      server.closeAllConnections();
    }
    setTimeout(finish, 2000).unref?.();
  });
}

/**
 * THE ADVERTISED CAPACITY MUST BE A DECISION, and it must be OUR decision for
 * the entries that are us.
 *
 * A record's `unknownWord1` lands at client record `+0x12a`, and `FUN_005bc990`
 * refuses the lobby with "Server full. You cannot participate." when the summed
 * player count reaches the selected entry's first record's copy of it
 * (`SERVER-SELECT-SPEC-2026-08-05.md` D.2, Observation). The rig fixture shipped
 * 4, inherited from V1's trace, and nothing in the system could tell that apart
 * from a capacity somebody chose - the rig-fixture gate only refuses 0.
 *
 * So two rules, both fail-closed:
 *   1. NOBODY may advertise 0. That is not a small capacity, it is a permanently
 *      full server: `sum >= 0` is true before the first player arrives.
 *   2. An entry pointing at THIS server must advertise exactly
 *      `PAL_V2_MAXIMUM_PLAYERS`, the number this process will actually admit.
 *      Entries pointing elsewhere are the operator's assertion about a machine
 *      we know nothing about, so only rule 1 applies to them - claiming to know
 *      another server's capacity would be the same invention this check exists
 *      to stop.
 *
 * LIMIT, stated rather than implied: this runs at startup, over the directory
 * file. A directory swapped in later through `directoryProvider.publish` is not
 * covered; that path belongs to `state/directory-source.js`.
 */
function assertDirectoryCapacityIsConfigured(directory, config) {
  const ourHosts = new Set(
    [config.snapHost, config.udpRegister?.bindAddress].filter((host) => host != null)
  );
  const problems = [];
  for (let index = 0; index < directory.entryCount; index += 1) {
    const entry = directory.entryAt(index);
    const host = Buffer.isBuffer(entry.host) ? entry.host.toString('latin1') : String(entry.host);
    const isThisServer = ourHosts.has(host);
    for (const record of entry.records) {
      const where = `entry ${entry.entryId} record ${record.recordId}`;
      if (record.unknownWord1 === 0) {
        problems.push(
          `${where} advertises 0 maximum players, which the client reads as permanently full`
        );
        continue;
      }
      if (isThisServer && record.unknownWord1 !== config.maximumPlayers) {
        problems.push(
          `${where} advertises ${record.unknownWord1} maximum players but points at this ` +
          `server (${host}), which admits ${config.maximumPlayers}; set PAL_V2_MAXIMUM_PLAYERS ` +
          'or the directory so the number the client gates on is the number we serve'
        );
      }
    }
  }
  if (problems.length === 0) return;
  const error = new Error(
    'the directory advertises a capacity this server did not decide:\n' +
    problems.map((problem) => `  - ${problem}`).join('\n')
  );
  error.code = 'DIRECTORY_CAPACITY';
  throw error;
}

/**
 * THE TWO RULES THE SHIPPED CONFIG ALREADY STATED AND NOTHING ENFORCED.
 *
 * `config/directory.example.json` tells operators both of these, and the review
 * of 2026-08-06 demonstrated that a one-entry directory and an entry with no
 * records both started cleanly - so the file was documentation, not a contract.
 *
 *   1. TWO ENTRIES, minimum. `FUN_00606fc0` substate 1 AUTO-SELECTS entry 1 and
 *      resolves immediately when the count is 0 or 1; the interactive list is
 *      drawn only from 2 up (`SERVER-SELECT-SPEC-2026-08-05.md` C.1/D.3). With
 *      one entry the player never chooses, and a host that then fails to resolve
 *      takes the screen-state-5 error path instead of the dialog - which is the
 *      harder failure to read on a rig.
 *   2. EVERY ENTRY NEEDS A RECORD. `0x6502` mode 0 skips a recordless entry, and
 *      `FUN_005c7bd0` dereferences `entry+0x160` unconditionally when it fills
 *      the UI row - so a recordless entry is not an empty row, it is a read of
 *      whatever is at that offset.
 *
 * Fail closed at startup, with the fix in the message: a directory is operator
 * data, and the operator is the only one who can correct it.
 */
function assertDirectoryIsSelectable(directory, directoryFile) {
  if (directory.entryCount < 2) {
    const error = new Error(
      `directory ${directoryFile} declares ${directory.entryCount} entr` +
      `${directory.entryCount === 1 ? 'y' : 'ies'}: the client auto-selects entry 1 below a ` +
      'count of 2 (FUN_00606fc0 substate 1) and never draws the list, so the player cannot ' +
      'choose. Add a second entry.'
    );
    error.code = 'DIRECTORY_ENTRY_COUNT';
    throw error;
  }
  for (let index = 0; index < directory.entryCount; index += 1) {
    const entry = directory.entryAt(index);
    if (entry.records.length > 0) continue;
    const error = new Error(
      `directory ${directoryFile} entry ${entry.entryId} has no records: 0x6502 mode 0 skips a ` +
      'recordless entry and FUN_005c7bd0 dereferences entry+0x160 unconditionally when it ' +
      'fills the UI row. Give every entry at least one record.'
    );
    error.code = 'DIRECTORY_ENTRY_WITHOUT_RECORDS';
    throw error;
  }
}

function listen(server, port, host) {
  return new Promise((resolve, reject) => {
    const onError = (error) => {
      server.off('listening', onListening);
      reject(error);
    };
    const onListening = () => {
      server.off('error', onError);
      resolve(server.address());
    };
    server.once('error', onError);
    server.once('listening', onListening);
    server.listen(port, host);
  });
}

export function createApplication({ config, logger, repositories = null }) {
  if (config == null) throw new TypeError('config is required');
  if (logger == null) throw new TypeError('logger is required');

  const started = [];
  let openedRepositories = null;
  let running = false;

  // ---- validated before any socket opens -------------------------------
  if (config.dataDirectory != null) {
    fs.mkdirSync(config.dataDirectory, { recursive: true });
  }

  const owned = repositories == null;
  const repos = repositories ?? openProductionRepositories({
    dataDirectory: config.dataDirectory,
    masterKey: config.masterKey
  });
  openedRepositories = owned ? repos : null;

  let directory;
  try {
    directory = loadDirectoryFile(config.directoryFile);
    // Production refuses a directory that declares itself a fixture. This is the
    // gate that stops convenient test data from becoming the served world.
    directory.assertServable({ allowTestFixture: false });
    if (directory.provenance !== DIRECTORY_PROVENANCE.OPERATOR) {
      throw new Error(
        `directory ${config.directoryFile} is not operator-provenance and cannot be served`
      );
    }
    // THE RIG / PRODUCTION BOUNDARY. A directory that declares itself the rig's
    // is exempt and says so loudly in the log; anything else is refused if it
    // still carries rig-only values. See docs/PROTOCOL-VALUE-INVENTORY.md.
    if (directory.rigFixture) {
      const findings = assertNoRigFixtureValues(directory, { enforce: false });
      logger.warn('directory-is-rig-fixture', {
        directoryFile: config.directoryFile,
        rigOnlyValues: findings,
        note: 'this configuration is NOT production; every finding must be closed before it is'
      });
    } else {
      assertNoRigFixtureValues(directory);
    }
    // Applies to the rig fixture too, deliberately: the wrong capacity breaks
    // the rig exactly as it breaks production, and the rig is where the
    // undecided 4 shipped.
    assertDirectoryCapacityIsConfigured(directory, config);
    // Applies to the rig fixture too, for the same reason the capacity check
    // does: a rig that auto-selects never exercises Server Select at all.
    assertDirectoryIsSelectable(directory, config.directoryFile);
  } catch (error) {
    // Construction failed after the database was opened; do not leak the handle.
    if (openedRepositories != null) {
      try {
        openedRepositories.database.close();
      } catch {
        // The original configuration error is the one worth reporting.
      }
      openedRepositories = null;
    }
    throw error;
  }

  const arming = new LobbyArmingRegistry();

  // Layer 2 of the session model: game-account sessions, established by the UDP
  // register + bind, which is the authentication event. See account-session.js.
  const accountSessions = new AccountSessionRegistry({
    // DETERMINISTIC RELEASE. Fired from the one place a session is forgotten,
    // so displacement (HTTP or UDP), expiry, explicit removal and shutdown all
    // release the owned LobbySession and its projection on the same path,
    // exactly once. Previously the HTTP displacement branch only logged, and
    // six logins for one account leaked six retained projections.
    onSessionReleased: (session) =>
      releaseLobbySession(session.accountSessionId, 'account-session-released')
  });
  /**
   * Lobby sessions by account-session id. These own the ClientDirectoryProjection
   * and outlive the TCP connection carrying them: the client retains its
   * directory state across a reset and afterwards fetches by a key issued on the
   * PREVIOUS connection, so a resume must reattach the same projection rather
   * than mint an empty one.
   */
  const lobbySessions = new Map();
  let cleanupTimer = null;

  function releaseLobbySession(accountSessionId, reason) {
    // Idempotent: repeated release of the same session is a no-op, so a path
    // that releases explicitly and then triggers the registry hook cannot
    // double-release or throw.
    const lobbySession = lobbySessions.get(accountSessionId);
    if (lobbySession == null) return false;
    lobbySessions.delete(accountSessionId);
    const projection = lobbySession.terminated ? null : lobbySession.projection;
    lobbySession.terminate();
    if (projection != null) lobbyProviders.releaseProjection(projection);
    logger.child('tcp10127').info('lobby-session-released', {
      lobbySessionId: lobbySession.lobbySessionId,
      userid: lobbySession.userid,
      reason
    });
    return true;
  }
  // Sized for hundreds of concurrent players rather than a single test rig.
  // These are the ceilings a full lobby actually reaches.
  const identity = new ConnectionIdentityRegistry({
    sessionLookup: (sessionConnectionId) => repos.sessions.get(sessionConnectionId),
    accountSessions
  });

  const directoryProvider = new PublishableDirectoryProvider(directory, {
    onPublish: (event) => logger.info('directory-published', event)
  });

  /*
   * Server Select's "Current players", derived from who is actually connected.
   *
   * The rig showed `0P` with a player signed in, because the `0x6510` word was
   * `record.unknownWord6510` - a configuration constant that no runtime input
   * ever touched. It would have read 0 with fifty players.
   *
   * This closure runs at ANSWER time, long after `presence` below is
   * initialised, so reading it here before its declaration is safe for the same
   * reason `onRoomEmptied` closing over `lobbyRooms` is: the binding is resolved
   * by the time anything calls it. A two-phase attach would instead permit a
   * build that is wired only halfway.
   *
   * WHICH entry gets the count: only the one that IS this process. The UDP
   * listener registers every presence under the entry id `'self'`, and we have
   * no telemetry for a directory entry pointing at some other host - so those
   * publish 0 rather than borrow our number. On the rig fixture both entries name
   * this same host, so both legitimately report the same live count.
   */
  const lobbyProviders = createDirectoryBackedProviders({
    directoryProvider,
    resolveCurrentPlayers: ({ entry }) =>
      (entry.host === config.udpRegister.bindAddress ? presence.countInServer('self') : 0)
  });

  // ---- services ---------------------------------------------------------
  const httpLogger = logger.child('http');
  const http = createWebService({
    accountRepository: repos.accounts,
    sessionRegistry: repos.sessions,
    selfHost: config.selfHost,
    snapHost: config.snapHost,
    snapPort: config.snapPort,
    descriptiveHexAddress: config.descriptiveHexAddress,
    lobbyName: config.lobbyName,
    welcomeMessage: config.welcomeMessage,
    logger: (record) => httpLogger.info('request', record),
    onLobbyProvisioned: ({ remote, sessionConnectionId, userid }) => {
      arming.arm(remote, { sessionConnectionId, userid });
      httpLogger.info('lobby-armed', { remote, sessionConnectionId, userid });
    },
    onSessionEstablished: ({ sessionConnectionId, userid, dnasToken, remote, action }) => {
      if (dnasToken == null) {
        // Not fatal, and not guessed around: the session exists, but no TCP
        // connection will be able to claim it.
        httpLogger.warn('session-without-dnas-token', { action, userid, remote });
        return;
      }
      identity.bindDnasToken({ dnasToken, sessionConnectionId });
      // An HTTP login is ALSO an account-authentication event - the password is
      // scrypt-verified - so it establishes a game-account session just as the
      // UDP register/bind does. This is what preserves the browser path: a
      // player who signs in and goes straight to the lobby is resolvable
      // without the token ever being an identity key.
      const established = accountSessions.establish({
        userid,
        sourceAddress: remote ?? null,
        // The scrypt check ran on this request before we were called, so this
        // establishment is entitled to replace a live session for the account.
        proof: ACCOUNT_PROOF.PASSWORD_VERIFIED
      });
      if (established.displaced != null) {
        httpLogger.info('account-session-displaced', {
          userid,
          displacedAccountSessionId: established.displaced.accountSessionId
        });
      }
      httpLogger.info('dnas-token-bound', {
        action,
        userid,
        sessionConnectionId,
        accountSessionId: established.session.accountSessionId
      });
    }
  });

  const tcpLogger = logger.child('tcp10127');
  const tcp = createTcp10127Service({
    /*
     * The served area table. SNAP_OPTION_LABELS ON appends the `+0x12fc`
     * option-label table as zero records (blank beats the stale-memory garbage
     * labels); SNAP_RULE_MASKS_AUTHENTIC ON serves the RULES-MASK-RE.md
     * create-screen bytes - the rule rows, cast mask and scenario ring that
     * make the create screen selectable. The flags are independent, and each
     * of the four byte images has its own version string (OBAREA-W3/V4/V5/V6)
     * because the client caches by version alone. Rollback for either = set it
     * false, which restores that dimension byte for byte.
     */
    areaTable: createV1ObservedAreaTable({
      publishOptionLabelTable: config.snapLobby?.optionLabels === true,
      publishAuthenticRuleMasks: config.snapLobby?.ruleMasksAuthentic === true
    }),
    resolveConnectionPurpose: ({ address }) => {
      const selected = arming.resolvePurpose(address);
      tcpLogger.debug('connection-purpose-selected', { address, purpose: selected });
      return selected;
    },
    maximumConnections: config.tcp.maximumConnections,
    logger: (event) => {
      const level = event.type === 'protocol-error' || event.type === 'socket-error'
        ? 'warn'
        : 'debug';
      tcpLogger[level](event.type, event);
    },
    /**
     * One projection and one identity per connection. Nothing is shared between
     * connections except the immutable directory snapshot, and closing a
     * connection releases exactly this connection's state.
     */
    createConnectionProviders: ({ remote }) => {
      const connectionRef = identity.openConnection({ remote });
      // The projection is deliberately NOT created here. A fresh initialization
      // creates it when its identity is established; a resume reattaches the one
      // its session already owns. Creating it per connection is what made the
      // resume fail: the client's retained record key matched an empty
      // projection and V2 closed the connection.
      let lobbySession = null;
      const providerBridge = {
        // THE ROUTE SELECTOR. Mode 1 sends the client into 0x6503, the only
        // command that writes its entry table; mode 0 on a 0x6501-first
        // connection keeps the state-5 route that already works. The policy is
        // in lobby-initialization-providers.js so it exists in exactly one
        // place - see its Inference note, and T32.
        resolveCommand6501Response: ({ resumed }) => selectCommand6501Mode({ resumed }),
        resolveCommand6503Response: ({ requestedStart, requestedCount }) =>
          requireLobbySession().projection.takeCommand6503Batch({
            start: requestedStart,
            count: requestedCount
          }),
        resolveCommand6502Response: (...args) =>
          requireLobbySession().projection.selectCommand6502Response(...args),
        resolveCommand6504Response: ({ sequence }) =>
          requireLobbySession().projection.takeCommand6504Batch({ sequence }),
        resolveCommand6510Response: ({ sequence, unknownEncodedRecordFields }) =>
          requireLobbySession().projection.resolveCommand6510Response({
            sequence,
            encodedRecordFields: unknownEncodedRecordFields
          })
      };

      function requireLobbySession() {
        if (lobbySession == null) {
          throw new Error('this connection has no lobby session');
        }
        if (!lobbySession.ownsTransport(connectionRef)) {
          // A superseded transport must not keep serving from the session it
          // no longer owns.
          throw new Error('this connection no longer owns its lobby session');
        }
        lobbySession.touch();
        /*
         * TOUCH THE ACCOUNT SESSION TOO, or an actively playing player is
         * disconnected at exactly 30 minutes.
         *
         * `AccountSessionRegistry` sweeps on `lastSeenAtMs`, which was written
         * once at claim time and never again: the transport refreshed only the
         * LOBBY session, so the 15-second cleanup eventually reaped the account
         * session of a player who was mid-game, which released the lobby
         * session under them and left the next provider call throwing
         * LOBBY_SESSION_TERMINATED on a live socket. Demonstrated with a fake
         * clock during the 2026-08-06 architecture audit; the docstring on the
         * registry noted that a long-lived connection did not refresh it, but
         * nothing recorded that the consequence was a hard cap on session
         * length. A scenario takes longer than 30 minutes, so this alone made
         * the project's completion criterion unreachable.
         */
        accountSessions.touch(lobbySession.accountSessionId);
        return lobbySession;
      }

      /*
       * THE CREATE-CONFIG DIALOGUE (SNAP_CREATE_CONFIG, default ON). Answers
       * the BIOSERVER-CONTRACT §6 create rows on TCP after the ladder
       * completes, against the SAME engine instances the UDP listener owns -
       * one room-status machine, one profile table - so a GAMESET flipped here
       * is the GAMESET op-0x49 reads. `snapLobbySessions` is declared later in
       * this file, but this factory runs per connection at runtime, when the
       * binding is resolved (the `onRoomEmptied` pattern). Without the UDP
       * subsystem there is no engine to configure, so no dialogue is attached
       * and post-completion frames keep the observed-not-answered behaviour.
       */
      const createConfigDialogue =
        (config.snapLobby?.createConfig === true && snapLobbySessions != null)
          ? new Tcp10127CreateConfigDialogue({
            roomLifecycle: snapLobbySessions.roomLifecycle,
            resolveProfile: () => {
              const session = requireLobbySession();
              return snapLobbySessions.profiles.get(session.accountSessionId)
                ?? snapLobbySessions.profiles.open({
                  accountSessionId: session.accountSessionId,
                  handle: session.userid
                });
            },
            resolveRoomHandle: () => {
              const session = requireLobbySession();
              return snapLobbySessions.presence.get(session.accountSessionId)?.roomHandle ?? null;
            },
            resolveAreaNumber: () => {
              const session = requireLobbySession();
              return snapLobbySessions.presence.get(session.accountSessionId)?.boxId ?? 0;
            },
            countMembers: (handle) => Math.max(1, snapLobbySessions.presence.countInRoom(handle)),
            broadcast: (scope, deliver) => snapLobbySessions.broadcast(scope, deliver),
            onSlotTitle: ({ handle, title }) => {
              // Mirror the title into the room record's display name when a
              // room exists and the name fits its 0x13-byte field; refusing a
              // longer one silently would hide the divergence, so it is logged.
              const room = snapLobbySessions.rooms.byHandle(handle);
              if (room == null) return;
              const text = title.toString('latin1');
              if (text.length === 0 || Buffer.byteLength(text, 'latin1') > 0x13) {
                tcpLogger.warn('create-config-title-not-mirrored', {
                  roomHandle: handle,
                  titleByteLength: title.length
                });
                return;
              }
              room.name = text;
            },
            now: () => Date.now(),
            logger: (event) => tcpLogger.debug(event.type ?? 'create-config', event)
          })
          : null;

      /*
       * THE LOBBY-BUTTON DIALOGUE (SNAP_LOBBY_BUTTONS, default ON). Answers
       * RANKINGS/GETINFO/BUDDYLIST/CHECKBUDDY per the bioserver reference
       * after the ladder completes - wire-inert until the client sends one
       * (RS1 inventory: none ever has on TCP). The buddy-status resolver is
       * the `getClientStatus` port: a live lobby session under that handle is
       * online (1), one whose profile carries a gamenumber is in a game (3),
       * anything else is offline (0).
       */
      const lobbyButtonsDialogue = config.snapLobby?.lobbyButtons === true
        ? new Tcp10127LobbyButtonsDialogue({
          resolveBuddyStatus: (handle) => {
            const name = handle.toString('latin1');
            for (const session of lobbySessions.values()) {
              if (session.userid !== name) continue;
              const profile = snapLobbySessions?.profiles.get(session.accountSessionId);
              return profile != null && profile.gamenumber > 0 ? 3 : 1;
            }
            return 0;
          },
          logger: (event) => tcpLogger.debug(event.type ?? 'lobby-buttons', event)
        })
        : null;

      return {
        ...providerBridge,
        createConfigDialogue,
        lobbyButtonsDialogue,
        associateDnasToken: ({ presentedToken }) => {
          const record = identity.associateConnection({
            connectionRef,
            dnasToken: presentedToken
          });
          // A fresh initialization creates the lobby session and its projection
          // ONCE. A repeat for the same account replaces the old one, because
          // the client has restarted its directory walk.
          releaseLobbySession(record.accountSessionId, 'replaced-by-fresh-initialization');
          lobbySession = new LobbySession({
            accountSessionId: record.accountSessionId,
            userid: record.userid,
            projection: lobbyProviders.createProjection()
          });
          lobbySession.attachTransport(connectionRef);
          lobbySessions.set(record.accountSessionId, lobbySession);
          tcpLogger.info('connection-associated', {
            connectionRef,
            sessionConnectionId: record.sessionConnectionId,
            userid: record.userid,
            lobbySessionId: lobbySession.lobbySessionId
          });
          return record;
        },
        // R-019: the resume connection's first frame is 0x6501 and it presents
        // no identity. It ATTACHES to the session that already completed an
        // initialization rather than creating one, so a resume can never be a
        // second, weaker way into an account.
        associateResumeSession: ({ sequence }) => {
          const record = identity.associateResumeConnection({ connectionRef, sequence });
          const existing = lobbySessions.get(record.accountSessionId);
          if (existing == null || !existing.resumable) {
            // Validated fully BEFORE anything is moved. The identity layer has
            // already claimed the account session, so give it back rather than
            // leaving it stranded.
            identity.closeConnection(connectionRef);
            const error = new Error(
              'no retained lobby session to resume; its directory state is gone'
            );
            error.code = 'NO_RETAINED_LOBBY_SESSION';
            throw error;
          }
          // REATTACH the existing projection. Not created, not cloned, not
          // rebuilt - this is the object that holds the record key the client
          // is about to ask for.
          const { superseded } = existing.attachTransport(connectionRef);
          lobbySession = existing;
          lobbySession.resumeCount += 1;
          tcpLogger.info('connection-resumed', {
            connectionRef,
            accountSessionId: record.accountSessionId,
            userid: record.userid,
            lobbySessionId: lobbySession.lobbySessionId,
            resumeCount: lobbySession.resumeCount,
            supersededTransport: superseded,
            note: 'the retained directory projection was reattached, not rebuilt'
          });
          return record;
        },
        onInitializationComplete: ({ resumed }) => {
          // Validated before anything is moved, matching the resume path above.
          // The identity call is the one that can throw (RESUMED_FLAG_REQUIRED),
          // so running it first stops a missing flag leaving the LobbySession
          // marked resumable while the account session is not.
          const session = identity.markInitializationComplete(connectionRef, { resumed });
          lobbySession?.markInitializationComplete();
          tcpLogger.info('lobby-initialization-recorded', {
            connectionRef,
            resumed,
            accountSessionId: session?.accountSessionId ?? null,
            userid: session?.userid ?? null,
            note: 'the session is now resumable by a 0x6501 connection'
          });
        },
        close: () => {
          // The transport is going away; the SESSION is not. Detaching only
          // clears the transport reference when this connection still owns it,
          // so a superseded socket closing later cannot evict the live one.
          //
          // The projection is retained deliberately: the client keeps its
          // directory state across the reset and will fetch by a key issued on
          // this connection. It is released when the account session expires.
          lobbySession?.detachTransport(connectionRef);
          identity.closeConnection(connectionRef);
        }
      };
    }
  });

  const dns = config.dns.enabled
    ? createDnsService({
      records: config.dns.records,
      ttl: config.dns.ttl,
      logger: (event) => logger.child('dns').debug(event.type ?? 'event', event)
    })
    : null;

  const dnas = config.dnas.enabled
    ? createConfiguredDnasService({
      certificatePath: config.dnas.certificatePath,
      caCertificatePath: config.dnas.caCertificatePath,
      privateKeyPath: config.dnas.privateKeyPath,
      packetDirectory: config.dnas.packetDirectory,
      logger: (event) => logger.child('dnas').debug(event.type ?? 'event', event),
      dynamicToken: config.dnas.dynamicToken === true,
      // A console doing DNAS is starting over, so anything we armed for its
      // previous session is stale. Without this, a player who reboots inside the
      // arming window has their BOOT-AUTH connection handed the lobby challenge
      // and the client raises D907.
      onPlatformSessionStart: (address) => {
        if (arming.disarm(address)) {
          logger.child('dnas').info('lobby-arming-cleared', {
            address,
            note: 'DNAS precedes boot auth; a stale arming would break it'
          });
        }
      },
      onDnasToken: ({ packetKey, token }) => {
        // Recorded so a rig run can be correlated: whatever the client presents
        // later in 0x1007 and ?DNAS= should be one of these.
        logger.child('dnas').info('platform-token-issued', { packetKey, token });
      }
    })
    : null;

  // The SN@P UDP :9090 register. Its account lookup keys on the LOGIN IDENTITY
  // the client carries in the request, and the reply body is Blowfish-encrypted
  // with that account's password - so this is the one place the reversible
  // compatibility secret is read at runtime.
  /*
   * THE ONE TIMING WHEEL, and the post-selection SN@P subsystem that uses it.
   *
   * One interval for the process rather than a Timeout per deadline: every
   * session in that phase needs a keepalive, a gap expiry and one retransmit
   * timer per unacknowledged message. It is created here and injected because
   * a service that made its own would reintroduce exactly what it removes.
   *
   * The keepalive key is `SNAP-SWAN`, which is what V1 shipped and what the
   * golden flag set carries (`deploy/pi-env.d/zzz-op40-keepalive.conf`). It is
   * passed explicitly - `SnapLobbySessions` has no default for it, because the
   * wrong key overruns an unmodified retail client's stack rather than merely
   * failing.
   */
  const snapTimingWheel = config.udpRegister.enabled
    ? createTimingWheel({
      onError: (report) => logger.child('udp9090').error('timing-callback-failed', {
        name: report.name,
        error: report.error
      })
    })
    : null;
  /*
   * PRESENCE AND ROOMS, constructed together because each derives from the other.
   *
   * Presence is the single home for WHERE every live player is, created at
   * bind-accept rather than at the op-0x06 ENTER - the ordering fix in
   * `analysis/PRESENCE-AND-COUNTS-DESIGN.md` section 1.3. Rooms hold identity and
   * capacity ONLY; a room's population is `presence.countInRoom(handle)` and its
   * existence ends with the transition that removes its last member, which is why
   * no ghost-room sweeper appears anywhere in this build.
   *
   * `onRoomEmptied` closes over `lobbyRooms` before it is initialised. That is
   * safe and deliberate: the hook is only ever CALLED from a later transition, by
   * which time the binding is resolved. The alternative - a two-phase `attach`
   * call - would let a build exist in which the two are wired only halfway.
   */
  const presence = new PresenceRegistry({
    maximumPresences: config.maximumPlayers,
    onRoomEmptied: (handle) => {
      lobbyRooms.close(handle);
      // The engine records (authored status, game session) close with the
      // room. Optional-chained forward reference, resolved by the time a room
      // can empty - the same pattern as `lobbyRooms` itself.
      snapLobbySessions?.releaseRoomState(handle);
    },
    logger: logger.child('presence')
  });
  const lobbyRooms = new LobbyRoomRegistry({
    countInRoom: (handle) => presence.countInRoom(handle)
  });
  const snapLobbySessions = snapTimingWheel == null
    ? null
    : new SnapLobbySessions({
      wheel: snapTimingWheel,
      // Content, with a stated provenance. Replaceable by an operator document
      // exactly as the directory and the area table are.
      areaDirectory: createV1ObservedAreaDirectory(),
      keepaliveKey: 'SNAP-SWAN',
      rooms: lobbyRooms,
      presence,
      /*
       * ONE capacity number, passed rather than defaulted. The client refuses the
       * lobby when the summed area populations reach the advertised `+0x12a`
       * (`FUN_005bc990`), and until now that advertised number was checked at
       * startup against a config value that governed no table at all - so the
       * refusal would have happened client-side, silently, with the server unaware
       * it caused it.
       */
      maximumSessions: config.maximumPlayers,
      /*
       * The SNAP_* experiment flags (`config.snapLobby`), every one defaulting
       * OFF. Optional-chained because programmatically built configs predate
       * the section; absence means every experiment is off, which is the same
       * bytes every previous build sent.
       */
      gameBeaconEcho: config.snapLobby?.gameBeaconEcho === true,
      gameBeaconRelay: config.snapLobby?.gameBeaconRelay === true,
      exitCloseMirror: config.snapLobby?.exitCloseMirror === true,
      completionSeqEcho: config.snapLobby?.completionSeqEcho === true,
      channelBitEcho: config.snapLobby?.channelBitEcho === true,
      roomChatSub7: config.snapLobby?.roomChatSub7 === true,
      gameRelay: config.snapLobby?.gameRelay === true,
      roomStat: config.snapLobby?.roomStat === true,
      reliableWindow: config.snapLobby?.reliableWindow ?? 32,
      memberIdToken: config.snapLobby?.memberIdToken === true,
      rosterToJoiner: config.snapLobby?.rosterToJoiner === true,
      hostReseat: config.snapLobby?.hostReseat === true,
      joinLadder: config.snapLobby?.joinLadder === true,
      op10Relay: config.snapLobby?.op10Relay === true,
      op0aCount0: config.snapLobby?.op0aCount0 === true,
      memberInfo: config.snapLobby?.memberInfo === true,
      roomFlagsPublish: config.snapLobby?.roomFlagsPublish === true,
      countPush: config.snapLobby?.countPush === true,
      appKeepalive: config.snapLobby?.appKeepalive === true,
      logger: logger.child('udp9090')
    });

  const udpRegister = config.udpRegister.enabled
    ? new SnapRegisterService({
      lobby: snapLobbySessions,
      bindAddress: config.udpRegister.bindAddress,
      // The client uses reply plaintext +0x28 for every post-register datagram
      // AND validates that replies come from it, so the advertised address must
      // be the address we actually bound.
      advertisedAddress: config.udpRegister.bindAddress,
      accountRepository: repos.accounts,
      logger: logger.child('udp9090'),
      port: config.udpRegister.port,
      // T33. `true` builds the default table; absent leaves the reply's tail
      // length at 0, which is byte-identical to every previous build.
      registrationNonces: config.udpRegister.attachmentNonce === true ? true : null,
      // A client whose memory card already holds an account never opens the
      // browser: it goes DNAS -> UDP register -> TCP lobby. Arming only from
      // `lbs.jsp` left every such connection classified as boot auth, and the
      // client reset it. V1 armed from the bind too.
      onLobbyReady: ({ address, loginIdentity, attachment = null }) => {
        // The nonce echo is the only thing in this exchange that distinguishes
        // the account holder from someone who merely typed their handle, so it
        // is what decides whether this establishment may replace a live session.
        // Everything else the bind carries - address, port, endpoint token,
        // endpoint name - is client-supplied and replayable.
        const proof = attachment?.verified === true
          ? ACCOUNT_PROOF.REGISTRATION_NONCE
          : ACCOUNT_PROOF.NONE;

        // ESTABLISH FIRST, ARM SECOND. A refused establishment must not leave
        // the sender's address armed for the lobby transcript in the victim's
        // name: arming grants no identity, but an address armed by a refusal is
        // a state change bought with nothing.
        let established;
        try {
          established = accountSessions.establish({
            userid: loginIdentity,
            sourceAddress: address,
            proof
          });
        } catch (error) {
          if (!(error instanceof AccountSessionError)) throw error;
          logger.child('udp9090').warn('account-session-refused', {
            address,
            userid: loginIdentity,
            code: error.code,
            attachment: attachment?.reason ?? null,
            reason: error.message,
            note: error.code === 'ACCOUNT_DISPLACEMENT_UNPROVEN'
              ? 'the live session for this account was KEPT; the sender proved nothing'
              : 'no account session was established for this bind'
          });
          return;
        }

        const { session, displaced } = established;
        if (displaced != null) {
          // The release itself is handled by the registry's onSessionReleased
          // hook, so every displacement path behaves identically.
          logger.child('udp9090').info('account-session-displaced', {
            userid: loginIdentity,
            displacedAccountSessionId: displaced.accountSessionId,
            proof,
            note: 'an account has at most one live game session'
          });
        }
        arming.arm(address, { userid: loginIdentity, source: 'udp9090-bind' });
        logger.child('udp9090').info('lobby-armed', {
          address,
          userid: loginIdentity,
          accountSessionId: session.accountSessionId,
          proof
        });
      }
    })
    : null;

  async function stop() {
    // Not an early return when nothing started: a failed bind still leaves the
    // database open, and an embedder calling stop() must get it back.
    running = false;
    if (cleanupTimer != null) {
      clearInterval(cleanupTimer);
      cleanupTimer = null;
    }
    // Shutdown is a release path like any other: every account session is
    // forgotten through #forget, which fires the hook that releases its
    // LobbySession and projection.
    accountSessions.clear();
    // Reverse of startup: stop accepting first, release the database last.
    for (const entry of [...started].reverse()) {
      try {
        await entry.close();
        logger.info('listener-stopped', { listener: entry.name });
      } catch (error) {
        logger.error('listener-stop-failed', { listener: entry.name, error });
      }
    }
    started.length = 0;
    if (openedRepositories != null) {
      const closing = openedRepositories;
      openedRepositories = null;
      try {
        closing.database.close();
      } catch (error) {
        logger.error('database-close-failed', { error });
      }
    }
    logger.info('stopped', {});
  }

  async function start() {
    if (running) throw new Error('application is already running');
    const plan = [
      { name: 'tcp10127', enabled: true, bind: () => listen(tcp, config.tcp.port, config.bindHost), close: () => closeHttpLike(tcp) },
      { name: 'http', enabled: true, bind: () => listen(http, config.http.port, config.bindHost), close: () => closeHttpLike(http) },
      { name: 'dnas', enabled: config.dnas.enabled, bind: () => listen(dnas, config.dnas.port, config.bindHost), close: () => closeHttpLike(dnas) },
      {
        name: 'dns',
        enabled: config.dns.enabled,
        bind: () => dns.listen({ host: config.bindHost, port: config.dns.port }),
        close: () => dns.close()
      },
      {
        name: 'udp9090',
        enabled: config.udpRegister.enabled,
        bind: async () => {
          // The wheel before the socket: the first datagram may arrive during
          // the callback that resolves the bind, and a session opened against a
          // stopped wheel would have a keepalive that never fires.
          if (!snapTimingWheel.running) snapTimingWheel.start();
          await udpRegister.start();
          return udpRegister.address();
        },
        close: async () => {
          // The socket first, so nothing new arrives; then the wheel, which
          // discards whatever the service's own release did not.
          await udpRegister.stop();
          const abandoned = snapTimingWheel.stop();
          if (abandoned > 0) {
            logger.child('udp9090').warn('timing-entries-abandoned', {
              abandoned,
              note: 'the wheel still held entries after every lobby session was released'
            });
          }
        }
      }
    ];

    for (const step of plan) {
      if (!step.enabled) {
        logger.info('listener-disabled', { listener: step.name });
        continue;
      }
      try {
        const address = await step.bind();
        started.push({ name: step.name, close: step.close });
        logger.info('listener-started', { listener: step.name, address });
      } catch (error) {
        logger.error('listener-failed', { listener: step.name, error });
        // Every required listener must be up, or none may be: roll back.
        await stop();
        const failure = new Error(
          `failed to bind ${step.name}: ${error.message}`
        );
        failure.code = 'LISTENER_BIND_FAILED';
        failure.listener = step.name;
        failure.cause = error;
        throw failure;
      }
    }

    // DETERMINISTIC CLEANUP, not only at lookup time. Expiry used to happen
    // solely inside the rate-limited sweep that runs on lookups, so an idle
    // server retained sessions - and their projections - indefinitely.
    cleanupTimer = setInterval(() => {
      try {
        accountSessions.sweepNow();
      } catch (error) {
        logger.error('cleanup-sweep-failed', { error: error.message });
      }
    }, CLEANUP_INTERVAL_MS);
    // Never hold the process open for a housekeeping timer.
    cleanupTimer.unref?.();

    running = true;
    logger.info('started', {
      directoryEntries: directory.entryCount,
      directoryRecords: directory.totalRecordCount,
      listeners: started.map((entry) => entry.name),
      // SAID OUT LOUD, because an empty room list is a real lobby state and a
      // silent one is a bug that looks identical. The count is the model's, so
      // a rig run can tell "no rooms exist" from "op-0x49 was never wired".
      lobbyRooms: lobbyRooms.size,
      lobbyRoomsNote: lobbyRooms.size === 0
        ? 'no rooms exist yet: nothing in this build opens one, so every in-area lobby renders ' +
          'empty. op-0x48 player counts ARE live and come from the sessions held.'
        : 'rooms are held from a previous run of this process'
    });
    return this;
  }

  return {
    start,
    stop,
    get running() {
      return running;
    },
    identity,
    arming,
    accountSessions,
    lobbySessions,
    releaseLobbySession,
    directoryProvider,
    lobbyProviders,
    // The room model and the post-selection session table, exposed so a test or
    // an operator tool can read what op-0x49 and op-0x48 will actually report.
    lobbyRooms,
    snapLobbySessions,
    // WHERE EVERY LIVE PLAYER IS. Exposed for the same reason as the two above:
    // an operator tool or a test must be able to read the state the counts are
    // derived from, rather than infer it from the replies.
    presence,
    repositories: repos,
    servers: { dns, dnas, http, tcp, udpRegister },
    addresses() {
      return {
        tcp: tcp.address(),
        http: http.address(),
        dnas: dnas == null ? null : dnas.address(),
        dns: dns == null ? null : dns.address(),
        udpRegister: udpRegister == null ? null : udpRegister.address()
      };
    }
  };
}
