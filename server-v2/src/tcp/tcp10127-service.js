import net from 'node:net';

import {
  TCP10127_DIRECTION,
  TCP10127_HEADER_LENGTH,
  Tcp10127StreamDecoder,
  encodeTcp10127Frame
} from '../protocol/tcp10127-codec.js';
import {
  TCP10127_LOBBY_INITIALIZATION_STATE,
  Tcp10127LobbyInitializationSession
} from './lobby-initialization-session.js';
import { createV1ObservedAreaTable } from '../state/area-table-v1.js';

const DEFAULT_IDLE_TIMEOUT_MS = 5_000;
/**
 * How long a single reply may take before it is worth reporting.
 *
 * NOT a timeout, and deliberately not a timer. The client's real ladder deadline
 * is the s16 at `0x365AD0`: 1800 pump ticks (~36 s PAL) between one complete
 * TCP-10127 message and the next, RE-ARMED by every framed inbound message with
 * no cumulative cap (`FUN_001c9b00` prologue, re-armed at `0x001c9c4c`). Seven
 * sequential `0x6204` round trips are therefore safe at any per-reply cost below
 * that. What matters is knowing if we ever approach it, so these two thresholds
 * are measured against a monotonic clock around a reply that is computed
 * synchronously. A wheel entry per request would be a timer that is always
 * cancelled in the same turn of the event loop - pure leak surface for no signal.
 */
const DEFAULT_REPLY_BUDGET_MS = 5_000;
const DEFAULT_REPLY_ALARM_MS = 20_000;
const DEFAULT_PRE_BROWSER_DELAYS_MS = Object.freeze([50, 100, 150]);
const DEFAULT_MAX_PENDING_BYTES = 0x10000 + TCP10127_HEADER_LENGTH;
const PRE_BROWSER_TRANSCRIPT = Object.freeze([0x1001, 0x1002, 0x1004]);

/**
 * The server-initiated frame that opens a lobby connection.
 *
 * The client never speaks first on TCP 10127. `SLES_533.19` receive-dispatch
 * entry `0x0c` binds command `0x6001` at direction `0x10` to `FUN_001c92d0`, so
 * the client ships a handler for exactly this unsolicited frame, and every
 * captured lobby connection opens with the server sending
 * `0000106001010000` - length 0, direction `0x10`, command `0x6001`,
 * sequence `0x01`, error 0, byte 7 zero - before the client sends `0x1007` or
 * `0x6501`. V1 sent the same bytes (`server/snap_server.js:1703`) and the real
 * client accepted them.
 */
const LOBBY_CHALLENGE = Object.freeze({
  command: 0x6001,
  direction: 0x10,
  sequence: 0x01,
  error: 0,
  unknown7: 0
});

function normalizeRemote(socket) {
  const address = socket.remoteAddress ?? '';
  return {
    address: address.startsWith('::ffff:') ? address.slice(7) : address,
    port: socket.remotePort ?? null
  };
}

function validateDelays(delays) {
  if (!Array.isArray(delays) || delays.length !== PRE_BROWSER_TRANSCRIPT.length) {
    throw new TypeError('preBrowserDelaysMs must contain exactly three delays');
  }
  for (let index = 0; index < delays.length; index += 1) {
    if (!Number.isSafeInteger(delays[index]) || delays[index] < 0) {
      throw new TypeError('preBrowserDelaysMs values must be non-negative integers');
    }
    if (index > 0 && delays[index] < delays[index - 1]) {
      throw new TypeError('preBrowserDelaysMs must be ordered');
    }
  }
  return [...delays];
}

/**
 * Create the bounded TCP 10127 listener for the initial connection slice.
 *
 * resolveConnectionPurpose is intentionally mandatory. The captured pre-browser
 * client sends no selector before the server's first write, so choosing a phase
 * from the TCP stream would be invented behavior. A later authenticated/session
 * slice must provide the resolver.
 */
export function createTcp10127Service({
  resolveConnectionPurpose,
  createConnectionProviders,
  resolveCommand6212Value,
  resolveCommand6211Value,
  resolveCommand6213Words,
  resolveCommand6501Response,
  resolveCommand6503Response,
  resolveCommand6502Response,
  resolveCommand6504Response,
  resolveCommand6510Response,
  /**
   * The area table every lobby connection is served.
   *
   * Server-wide CONTENT, not per-connection state: the ten Area-Select boxes are
   * the same for every player, and a per-connection provider would be false
   * precision. It defaults to the table V1 served on the run that rendered Area
   * Select on real PS2 hardware, which is the only area table known to work; the
   * module states that provenance and the service reports it, so nothing about
   * the default is hidden. An operator table replaces it here without any
   * protocol code changing - see `parseAreaTableDocument` in
   * `src/state/area-table.js`.
   */
  areaTable = createV1ObservedAreaTable(),
  logger = () => {},
  idleTimeoutMs = DEFAULT_IDLE_TIMEOUT_MS,
  replyBudgetMs = DEFAULT_REPLY_BUDGET_MS,
  replyAlarmMs = DEFAULT_REPLY_ALARM_MS,
  preBrowserDelaysMs = DEFAULT_PRE_BROWSER_DELAYS_MS,
  maximumConnections = 256,
  maxPendingBytes = DEFAULT_MAX_PENDING_BYTES,
  maxPayloadLength = 0xffff
} = {}) {
  if (typeof resolveConnectionPurpose !== 'function') {
    throw new TypeError('resolveConnectionPurpose is required');
  }
  if (areaTable == null || typeof areaTable.chunkLengths !== 'function') {
    throw new TypeError('areaTable must expose the AreaTable interface');
  }
  for (const [name, value] of [['replyBudgetMs', replyBudgetMs], ['replyAlarmMs', replyAlarmMs]]) {
    if (!Number.isSafeInteger(value) || value <= 0) {
      throw new TypeError(`${name} must be a positive integer`);
    }
  }
  if (replyAlarmMs < replyBudgetMs) {
    throw new TypeError('replyAlarmMs must not be below replyBudgetMs');
  }
  if (createConnectionProviders != null && typeof createConnectionProviders !== 'function') {
    throw new TypeError('createConnectionProviders must be a function when provided');
  }
  // Silently preferring one form over the other would degrade three replies to
  // their client-default branch with no signal, so a caller supplying both is a
  // composition mistake and is refused outright.
  if (createConnectionProviders != null) {
    const conflicting = [
      ['resolveCommand6212Value', resolveCommand6212Value],
      ['resolveCommand6211Value', resolveCommand6211Value],
      ['resolveCommand6213Words', resolveCommand6213Words],
      ['resolveCommand6501Response', resolveCommand6501Response],
      ['resolveCommand6503Response', resolveCommand6503Response],
      ['resolveCommand6502Response', resolveCommand6502Response],
      ['resolveCommand6504Response', resolveCommand6504Response],
      ['resolveCommand6510Response', resolveCommand6510Response]
    ].filter(([, value]) => value != null).map(([name]) => name);
    if (conflicting.length > 0) {
      throw new TypeError(
        'createConnectionProviders cannot be combined with flat providers: ' +
        conflicting.join(', ')
      );
    }
  }
  if (resolveCommand6212Value != null && typeof resolveCommand6212Value !== 'function') {
    throw new TypeError('resolveCommand6212Value must be a function when provided');
  }
  if (resolveCommand6211Value != null && typeof resolveCommand6211Value !== 'function') {
    throw new TypeError('resolveCommand6211Value must be a function when provided');
  }
  if (resolveCommand6213Words != null && typeof resolveCommand6213Words !== 'function') {
    throw new TypeError('resolveCommand6213Words must be a function when provided');
  }
  if (resolveCommand6501Response != null && typeof resolveCommand6501Response !== 'function') {
    throw new TypeError('resolveCommand6501Response must be a function when provided');
  }
  if (resolveCommand6503Response != null && typeof resolveCommand6503Response !== 'function') {
    throw new TypeError('resolveCommand6503Response must be a function when provided');
  }
  if (resolveCommand6502Response != null && typeof resolveCommand6502Response !== 'function') {
    throw new TypeError('resolveCommand6502Response must be a function when provided');
  }
  if (resolveCommand6504Response != null && typeof resolveCommand6504Response !== 'function') {
    throw new TypeError('resolveCommand6504Response must be a function when provided');
  }
  if (resolveCommand6510Response != null && typeof resolveCommand6510Response !== 'function') {
    throw new TypeError('resolveCommand6510Response must be a function when provided');
  }
  if (!Number.isSafeInteger(idleTimeoutMs) || idleTimeoutMs <= 0) {
    throw new TypeError('idleTimeoutMs must be a positive integer');
  }
  if (!Number.isSafeInteger(maximumConnections) || maximumConnections <= 0) {
    throw new TypeError('maximumConnections must be a positive integer');
  }
  if (!Number.isSafeInteger(maxPendingBytes) || maxPendingBytes <= 0) {
    throw new TypeError('maxPendingBytes must be a positive integer');
  }
  const delays = validateDelays(preBrowserDelaysMs);

  // Said once, at startup, so a rig log records WHICH area table went out before
  // any client arrives rather than leaving it to be inferred from the wire.
  logger({
    type: 'area-table-selected',
    provenance: areaTable.provenance,
    version: areaTable.version.toString('latin1'),
    byteLength: areaTable.byteLength,
    areaCount: areaTable.areaCount,
    sliceCount: areaTable.sliceCount
  });

  const server = net.createServer((socket) => {
    const remote = normalizeRemote(socket);
    const decoder = new Tcp10127StreamDecoder({ maxPayloadLength });
    const timers = new Set();
    const pendingChunks = [];
    let purpose = null;
    let lobbyInitializationSession = null;
    // Per-connection providers, when the caller supplies a factory. Their state
    // belongs to this connection and is released with it.
    let connectionProviders = null;
    let closed = false;
    let bytesReceivedBeforePurpose = 0;
    // Captured real-client behaviour: the client, not the server, ends the
    // connection once it has the 0x1004 reply. On real PS2 hardware it sends RST
    // ~70 ms later (2026_05_30 REALPS2 pcap frames 1259-1262); on the emulator it
    // sends a graceful FIN at the same point (2026_05_31 EMULATOR pcap frames
    // 309-316). A reset after completion is therefore normal termination, not a
    // fault, and the server must never close first.
    let lobbyInitializationCompleted = false;

    const clearTimers = () => {
      for (const timer of timers) clearTimeout(timer);
      timers.clear();
    };

    const closeForProtocolError = (errorCode, message) => {
      logger({ type: 'protocol-error', remote, purpose, errorCode, message });
      clearTimers();
      closed = true;
      socket.destroy();
    };

    const processLobbyInitializationChunk = (chunk) => {
      const frames = decoder.push(chunk);
      for (const frame of frames) {
        logger({
          type: 'frame-receive',
          remote,
          purpose,
          command: frame.command,
          sequence: frame.sequence,
          length: frame.raw.length
        });
        const startedAtMs = performance.now();
        try {
          const result = lobbyInitializationSession.handleFrame(frame);
          const elapsedMs = performance.now() - startedAtMs;
          if (elapsedMs >= replyBudgetMs) {
            logger({
              type: elapsedMs >= replyAlarmMs ? 'reply-latency-alarm' : 'reply-latency-warning',
              remote,
              purpose,
              command: frame.command,
              elapsedMs,
              replyBudgetMs,
              replyAlarmMs
            });
          }
          if (result.unimplemented) {
            logger({
              type: 'unimplemented-frame',
              remote,
              purpose,
              command: frame.command,
              sequence: frame.sequence,
              length: frame.raw.length,
              state: result.state,
              // A post-completion dialogue REFUSAL that fell back to
              // observed-not-answered carries its named code; a frame nothing
              // handles carries none. Same log line, attributable cause.
              ...(result.refusal != null ? { refusal: result.refusal } : {})
            });
            continue;
          }
          /*
           * Broadcast pushes on the REFERENCE'S per-row side of the TELL:
           * `broadcasts` before it (CREATESLOT/0x6504 - "broadcasts ...; then
           * TELL"), `broadcastsAfterTell` after it (SLOTNAME - the reference
           * queues the TELL first, `PacketHandler.java:1256-1257`). Only the
           * create-config dialogue returns either; every other handler leaves
           * both fields absent and this writes nothing.
           */
          if (Array.isArray(result.broadcasts) && result.broadcasts.length > 0) {
            for (const push of result.broadcasts) socket.write(push);
            logger({
              type: 'create-config-pushes',
              remote,
              purpose,
              command: frame.command,
              pushCount: result.broadcasts.length
            });
          }
          socket.write(result.response);
          if (Array.isArray(result.broadcastsAfterTell) &&
              result.broadcastsAfterTell.length > 0) {
            for (const push of result.broadcastsAfterTell) socket.write(push);
            logger({
              type: 'create-config-pushes',
              remote,
              purpose,
              command: frame.command,
              pushCount: result.broadcastsAfterTell.length,
              afterTell: true
            });
          }
          logger({
            type: 'frame-send',
            remote,
            purpose,
            command: frame.command,
            sequence: frame.sequence,
            length: result.response.length,
            state: result.state
          });
          if (result.state ===
              TCP10127_LOBBY_INITIALIZATION_STATE.LOBBY_INITIALIZATION_COMPLETE &&
              !lobbyInitializationCompleted) {
            lobbyInitializationCompleted = true;
            logger({ type: 'lobby-initialization-complete', remote, purpose });
          }
        } catch (error) {
          closeForProtocolError(error.code ?? 'TCP10127_LOBBY_INIT', error.message);
          return;
        }
      }
    };

    /**
     * Open a lobby connection the way every captured one opens. Sent before any
     * buffered client bytes are replayed, so the ordering on the wire matches
     * the captures even when the client's first frame arrived early.
     */
    const sendLobbyChallenge = () => {
      if (closed) return;
      const frame = encodeTcp10127Frame({
        direction: LOBBY_CHALLENGE.direction,
        command: LOBBY_CHALLENGE.command,
        sequence: LOBBY_CHALLENGE.sequence,
        error: LOBBY_CHALLENGE.error,
        unknown7: LOBBY_CHALLENGE.unknown7,
        payload: Buffer.alloc(0)
      });
      socket.write(frame);
      logger({
        type: 'frame-send',
        remote,
        purpose,
        command: LOBBY_CHALLENGE.command,
        length: frame.length
      });
    };

    /** Replay bytes that arrived while the purpose resolver was still pending. */
    const drainPendingLobbyChunks = () => {
      logger({ type: 'connection-open', remote, purpose });
      try {
        for (const chunk of pendingChunks) {
          if (closed) break;
          processLobbyInitializationChunk(chunk);
        }
      } catch (error) {
        closeForProtocolError(error.code ?? 'TCP10127_DECODE', error.message);
      }
      pendingChunks.length = 0;
    };

    socket.setNoDelay(true);
    socket.setTimeout(idleTimeoutMs);

    socket.on('data', (chunk) => {
      if (purpose == null) {
        if (bytesReceivedBeforePurpose + chunk.length > maxPendingBytes) {
          closeForProtocolError(
            'PRE_PURPOSE_BUFFER_LIMIT',
            `client bytes before purpose resolution exceed ${maxPendingBytes}`
          );
          return;
        }
        bytesReceivedBeforePurpose += chunk.length;
        pendingChunks.push(Buffer.from(chunk));
        return;
      }
      if (purpose === 'pre-browser') {
        closeForProtocolError(
          'UNEXPECTED_PRE_BROWSER_BYTES',
          'captured pre-browser connection sends no client application bytes'
        );
        return;
      }
      try {
        if (purpose === 'lobby-initialization') {
          processLobbyInitializationChunk(chunk);
        } else {
          decoder.push(chunk);
        }
      } catch (error) {
        closeForProtocolError(error.code ?? 'TCP10127_DECODE', error.message);
      }
    });

    socket.on('timeout', () => {
      logger({ type: 'connection-timeout', remote, purpose, idleTimeoutMs });
      clearTimers();
      socket.destroy();
    });
    socket.on('error', (error) => {
      const errorCode = error.code ?? 'TCP10127_SOCKET';
      // A reset once lobby initialization has completed is the captured PS2
      // client's normal way of ending the connection, so it must not be reported
      // as a fault.
      if (errorCode === 'ECONNRESET' && lobbyInitializationCompleted) {
        logger({ type: 'expected-client-reset', remote, purpose });
        return;
      }
      logger({
        type: 'socket-error',
        remote,
        purpose,
        errorCode,
        message: error.message
      });
    });
    socket.on('close', () => {
      closed = true;
      clearTimers();
      if (connectionProviders != null && typeof connectionProviders.close === 'function') {
        connectionProviders.close();
      }
      connectionProviders = null;
      logger({ type: 'connection-close', remote, purpose, lobbyInitializationCompleted });
    });

    Promise.resolve()
      .then(() => resolveConnectionPurpose({ ...remote }))
      .then((resolvedPurpose) => {
        if (closed) return;
        purpose = resolvedPurpose;
        if (purpose === 'lobby-initialization') {
          // A per-connection factory owns state that belongs to one client, so
          // it wins over the flat providers when both are supplied.
          if (createConnectionProviders != null) {
            try {
              connectionProviders = createConnectionProviders({ remote: { ...remote } });
            } catch (error) {
              closeForProtocolError(
                'CONNECTION_PROVIDER_FACTORY',
                `connection provider factory failed: ${error.message}`
              );
              return;
            }
            if (connectionProviders == null ||
                typeof connectionProviders.resolveCommand6501Response !== 'function') {
              closeForProtocolError(
                'MISSING_COMMAND_6501_RESPONSE_RESOLVER',
                'connection provider factory returned no resolveCommand6501Response'
              );
              return;
            }
            lobbyInitializationSession = new Tcp10127LobbyInitializationSession({
              areaTable,
              // The identity hook belongs to the connection, so it can only come
              // from the per-connection factory. Without this the 0x1007 token is
              // decoded and then ignored, and any client would be served.
              associateDnasToken: connectionProviders.associateDnasToken,
              // The create-config dialogue is per-connection state, so like the
              // identity hooks it can only come from the factory.
              createConfigDialogue: connectionProviders.createConfigDialogue ?? null,
              // The lobby-button dialogue (SNAP_LOBBY_BUTTONS): same rule.
              lobbyButtonsDialogue: connectionProviders.lobbyButtonsDialogue ?? null,
              associateResumeSession: connectionProviders.associateResumeSession,
              onInitializationComplete: connectionProviders.onInitializationComplete,
              resolveCommand6212Value: connectionProviders.resolveCommand6212Value,
              resolveCommand6211Value: connectionProviders.resolveCommand6211Value,
              resolveCommand6213Words: connectionProviders.resolveCommand6213Words,
              resolveCommand6501Response: connectionProviders.resolveCommand6501Response,
              resolveCommand6503Response: connectionProviders.resolveCommand6503Response,
              resolveCommand6502Response: connectionProviders.resolveCommand6502Response,
              resolveCommand6504Response: connectionProviders.resolveCommand6504Response,
              resolveCommand6510Response: connectionProviders.resolveCommand6510Response
            });
            sendLobbyChallenge();
            drainPendingLobbyChunks();
            return;
          }
          if (typeof resolveCommand6501Response !== 'function') {
            closeForProtocolError(
              'MISSING_COMMAND_6501_RESPONSE_RESOLVER',
              'lobby-initialization requires resolveCommand6501Response'
            );
            return;
          }
          lobbyInitializationSession = new Tcp10127LobbyInitializationSession({
            areaTable,
            resolveCommand6212Value: resolveCommand6212Value == null
              ? undefined
              : (request) => resolveCommand6212Value({ remote: { ...remote }, ...request }),
            resolveCommand6211Value: resolveCommand6211Value == null
              ? undefined
              : (request) => resolveCommand6211Value({ remote: { ...remote }, ...request }),
            resolveCommand6213Words: resolveCommand6213Words == null
              ? undefined
              : (request) => resolveCommand6213Words({ remote: { ...remote }, ...request }),
            resolveCommand6501Response: (request) => resolveCommand6501Response({
              remote: { ...remote },
              ...request
            }),
            resolveCommand6503Response: resolveCommand6503Response == null
              ? undefined
              : (request) => resolveCommand6503Response({ remote: { ...remote }, ...request }),
            resolveCommand6502Response: resolveCommand6502Response == null
              ? undefined
              : (request) => resolveCommand6502Response({ remote: { ...remote }, ...request }),
            resolveCommand6504Response: resolveCommand6504Response == null
              ? undefined
              : (request) => resolveCommand6504Response({ remote: { ...remote }, ...request }),
            resolveCommand6510Response: resolveCommand6510Response == null
              ? undefined
              : (request) => resolveCommand6510Response({ remote: { ...remote }, ...request })
          });
          sendLobbyChallenge();
          drainPendingLobbyChunks();
          return;
        }
        if (purpose !== 'pre-browser') {
          closeForProtocolError(
            purpose == null ? 'UNRESOLVED_CONNECTION_PURPOSE' : 'UNSUPPORTED_CONNECTION_PURPOSE',
            purpose == null
              ? 'connection purpose resolver returned no purpose'
              : `connection purpose ${String(purpose)} is not implemented in this slice`
          );
          return;
        }
        if (bytesReceivedBeforePurpose !== 0) {
          closeForProtocolError(
            'UNEXPECTED_PRE_BROWSER_BYTES',
            'client bytes arrived before pre-browser purpose resolution'
          );
          return;
        }

        logger({ type: 'connection-open', remote, purpose });
        PRE_BROWSER_TRANSCRIPT.forEach((command, index) => {
          const timer = setTimeout(() => {
            timers.delete(timer);
            if (closed) return;
            const frame = encodeTcp10127Frame({
              direction: TCP10127_DIRECTION.SERVER_RESPONSE,
              command,
              sequence: 0,
              error: 0,
              unknown7: 0,
              payload: Buffer.alloc(0)
            });
            socket.write(frame);
            logger({ type: 'frame-send', remote, purpose, command, length: frame.length });
          }, delays[index]);
          timers.add(timer);
        });
      })
      .catch((error) => closeForProtocolError(
        'CONNECTION_PURPOSE_RESOLVER',
        error.message
      ));
  });

  server.maxConnections = maximumConnections;
  return server;
}

export const TCP10127_SERVICE_DEFAULTS = Object.freeze({
  idleTimeoutMs: DEFAULT_IDLE_TIMEOUT_MS,
  replyBudgetMs: DEFAULT_REPLY_BUDGET_MS,
  replyAlarmMs: DEFAULT_REPLY_ALARM_MS,
  preBrowserDelaysMs: DEFAULT_PRE_BROWSER_DELAYS_MS,
  maximumConnections: 256,
  maxPendingBytes: DEFAULT_MAX_PENDING_BYTES,
  maxPayloadLength: 0xffff
});
