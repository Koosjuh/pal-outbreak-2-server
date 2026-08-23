import crypto from 'node:crypto';
import fs from 'node:fs';
import net from 'node:net';

import { DnasApplicationService } from './application-codec.js';
import { LegacyDnasTlsConnection, LegacyTlsError } from './legacy-tls.js';
import { DynamicTokenDnasPacketStore } from './dynamic-token-packet-store.js';
import { FileDnasPacketStore } from './packet-store.js';

const DEFAULT_IDLE_TIMEOUT_MS = 5_000;
const DEFAULT_MAX_CONNECTIONS = 256;

function normalizeRemote(socket) {
  const address = socket.remoteAddress ?? '';
  return {
    address: address.startsWith('::ffff:') ? address.slice(7) : address,
    port: socket.remotePort ?? null
  };
}

function writeWithBackpressure(socket, bytes) {
  return new Promise((resolve, reject) => {
    if (socket.destroyed || !socket.writable) {
      reject(new Error('DNAS socket is no longer writable'));
      return;
    }
    const accepted = socket.write(bytes, (error) => {
      if (error) reject(error);
    });
    if (accepted) {
      resolve();
      return;
    }
    const onDrain = () => {
      cleanup();
      resolve();
    };
    const onError = (error) => {
      cleanup();
      reject(error);
    };
    const cleanup = () => {
      socket.off('drain', onDrain);
      socket.off('error', onError);
    };
    socket.once('drain', onDrain);
    socket.once('error', onError);
  });
}

export function createDnasService({
  connectionFactory,
  idleTimeoutMs = DEFAULT_IDLE_TIMEOUT_MS,
  maximumConnections = DEFAULT_MAX_CONNECTIONS,
  logger = () => {}
}) {
  if (typeof connectionFactory !== 'function') {
    throw new TypeError('DNAS connectionFactory is required');
  }
  if (!Number.isSafeInteger(idleTimeoutMs) || idleTimeoutMs <= 0) {
    throw new TypeError('DNAS idleTimeoutMs must be a positive integer');
  }
  if (!Number.isSafeInteger(maximumConnections) || maximumConnections <= 0) {
    throw new TypeError('DNAS maximumConnections must be a positive integer');
  }

  let nextConnectionId = 1;
  const server = net.createServer((socket) => {
    const connectionId = nextConnectionId;
    nextConnectionId += 1;
    const remote = normalizeRemote(socket);
    let connection;
    let emittedEventCount = 0;
    let processing = Promise.resolve();

    try {
      connection = connectionFactory({ connectionId, remote });
    } catch (error) {
      logger({
        type: 'connection-factory-error',
        connectionId,
        remote,
        errorCode: error.code ?? 'CONNECTION_FACTORY_FAILED',
        message: error.message
      });
      socket.destroy();
      return;
    }

    logger({ type: 'connection-open', connectionId, remote });
    socket.setTimeout(idleTimeoutMs);
    socket.setNoDelay(true);
    socket.setKeepAlive(true, 1_000);

    function emitTlsEvents() {
      while (emittedEventCount < connection.events.length) {
        logger({
          type: 'tls-event',
          connectionId,
          remote,
          event: connection.events[emittedEventCount]
        });
        emittedEventCount += 1;
      }
    }

    socket.on('data', (chunk) => {
      socket.pause();
      processing = processing
        .then(async () => {
          const writes = await connection.feed(chunk);
          emitTlsEvents();
          for (const bytes of writes) {
            await writeWithBackpressure(socket, bytes);
          }
          if (connection.closedByPeer && !socket.writableEnded) {
            socket.end();
          }
        })
        .catch((error) => {
          emitTlsEvents();
          logger({
            type: error instanceof LegacyTlsError ? 'protocol-error' : 'connection-error',
            connectionId,
            remote,
            errorCode: error.code ?? 'DNAS_CONNECTION_ERROR',
            message: error.message
          });
          socket.destroy();
        })
        .finally(() => {
          if (!socket.destroyed && !socket.writableEnded) {
            socket.resume();
          }
        });
    });

    socket.on('timeout', () => {
      logger({ type: 'connection-timeout', connectionId, remote, idleTimeoutMs });
      socket.destroy();
    });
    socket.on('end', () => {
      logger({ type: 'connection-end', connectionId, remote });
    });
    socket.on('close', (hadError) => {
      logger({ type: 'connection-close', connectionId, remote, hadError });
    });
    socket.on('error', (error) => {
      logger({
        type: 'socket-error',
        connectionId,
        remote,
        errorCode: error.code ?? 'SOCKET_ERROR',
        message: error.message
      });
    });
  });
  server.maxConnections = maximumConnections;
  return server;
}

export function createConfiguredDnasService({
  certificatePath,
  caCertificatePath,
  privateKeyPath,
  packetDirectory,
  idleTimeoutMs = DEFAULT_IDLE_TIMEOUT_MS,
  maximumConnections = DEFAULT_MAX_CONNECTIONS,
  logger = () => {},
  randomBytes = crypto.randomBytes,
  // OQ-023 experiment: give each DNAS session its own platform-session token
  // instead of replaying the one baked into the static asset. Opt-in.
  dynamicToken = false,
  generateDnasToken = null,
  onDnasToken = null,
  // Called with the remote address when a console starts a DNAS exchange. DNAS
  // precedes boot auth on a fresh start, so this is the server's signal that
  // whatever it remembered about that console is stale.
  onPlatformSessionStart = null
}) {
  for (const [name, value] of Object.entries({
    certificatePath,
    caCertificatePath,
    privateKeyPath,
    packetDirectory
  })) {
    if (!value) throw new TypeError(`${name} is required`);
  }
  if (typeof randomBytes !== 'function') {
    throw new TypeError('DNAS randomBytes must be a function');
  }

  const certificateDer = Buffer.from(
    new crypto.X509Certificate(fs.readFileSync(certificatePath, 'utf8')).raw
  );
  const caCertificateDer = Buffer.from(
    new crypto.X509Certificate(fs.readFileSync(caCertificatePath, 'utf8')).raw
  );
  const privateKey = crypto.createPrivateKey(fs.readFileSync(privateKeyPath, 'utf8'));
  const fileStore = new FileDnasPacketStore(packetDirectory);
  const packetStore = dynamicToken
    ? new DynamicTokenDnasPacketStore({
      store: fileStore,
      generateToken: generateDnasToken,
      onToken: onDnasToken
    })
    : fileStore;
  const applicationService = new DnasApplicationService({ packetStore });

  return createDnasService({
    idleTimeoutMs,
    maximumConnections,
    logger: (event) => {
      if (event?.type === 'connection-open' && event.remote?.address != null) {
        onPlatformSessionStart?.(event.remote.address);
      }
      logger(event);
    },
    connectionFactory: () => new LegacyDnasTlsConnection({
      certificateDer,
      caCertificateDer,
      privateKey,
      applicationService,
      serverRandom: randomBytes(32)
    })
  });
}

export const DNAS_SERVICE_DEFAULTS = Object.freeze({
  idleTimeoutMs: DEFAULT_IDLE_TIMEOUT_MS,
  maximumConnections: DEFAULT_MAX_CONNECTIONS
});
