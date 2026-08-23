import dgram from 'node:dgram';
import net from 'node:net';

import { DNS_CONSTANTS, DnsProtocolError, buildDnsResponse, normalizeDnsRecords } from './dns-codec.js';

const DEFAULT_TCP_IDLE_TIMEOUT_MS = 5_000;

export function createDnsService({
  records,
  ttl = 60,
  logger = () => {},
  tcpIdleTimeoutMs = DEFAULT_TCP_IDLE_TIMEOUT_MS
}) {
  if (!Number.isSafeInteger(tcpIdleTimeoutMs) || tcpIdleTimeoutMs <= 0) {
    throw new TypeError('DNS TCP idle timeout must be a positive integer');
  }
  const recordMap = normalizeDnsRecords(records);
  const udp = dgram.createSocket('udp4');
  const tcp = net.createServer();
  let listening = false;
  let listenAddress = null;

  function answer(message, transport, remote) {
    try {
      const response = buildDnsResponse(message, recordMap, { ttl });
      logger({
        type: 'query',
        transport,
        remote,
        name: response.query.name,
        queryType: response.query.type,
        rcode: response.rcode,
        answerCount: response.answerCount
      });
      return response.bytes;
    } catch (error) {
      logger({
        type: error instanceof DnsProtocolError ? 'protocol-error' : 'service-error',
        transport,
        remote,
        errorCode: error.code ?? 'DNS_SERVICE_ERROR',
        message: error.message
      });
      return null;
    }
  }

  udp.on('message', (message, remoteInfo) => {
    const remote = { address: remoteInfo.address, port: remoteInfo.port };
    const response = answer(message, 'udp', remote);
    if (response) {
      udp.send(response, remoteInfo.port, remoteInfo.address);
    }
  });
  udp.on('error', (error) => logger({
    type: 'socket-error',
    transport: 'udp',
    errorCode: error.code ?? 'DNS_UDP_ERROR',
    message: error.message
  }));

  tcp.on('connection', (socket) => {
    const address = socket.remoteAddress ?? '';
    const remote = {
      address: address.startsWith('::ffff:') ? address.slice(7) : address,
      port: socket.remotePort ?? null
    };
    let buffer = Buffer.alloc(0);
    socket.setTimeout(tcpIdleTimeoutMs);
    socket.setNoDelay(true);
    socket.on('data', (chunk) => {
      buffer = Buffer.concat([buffer, chunk]);
      while (buffer.length >= 2) {
        const length = buffer.readUInt16BE(0);
        if (length === 0 || length > DNS_CONSTANTS.MAX_DNS_MESSAGE) {
          logger({ type: 'protocol-error', transport: 'tcp', remote, errorCode: 'TCP_LENGTH' });
          socket.destroy();
          return;
        }
        if (buffer.length < length + 2) return;
        const message = buffer.subarray(2, length + 2);
        buffer = buffer.subarray(length + 2);
        const response = answer(message, 'tcp', remote);
        if (!response) {
          socket.destroy();
          return;
        }
        const framed = Buffer.alloc(response.length + 2);
        framed.writeUInt16BE(response.length, 0);
        response.copy(framed, 2);
        socket.write(framed);
      }
    });
    socket.on('timeout', () => {
      logger({ type: 'connection-timeout', transport: 'tcp', remote, tcpIdleTimeoutMs });
      socket.destroy();
    });
    socket.on('error', (error) => logger({
      type: 'socket-error',
      transport: 'tcp',
      remote,
      errorCode: error.code ?? 'DNS_TCP_ERROR',
      message: error.message
    }));
  });
  tcp.on('error', (error) => logger({
    type: 'server-error',
    transport: 'tcp',
    errorCode: error.code ?? 'DNS_TCP_SERVER_ERROR',
    message: error.message
  }));

  return {
    records: new Map(recordMap),
    async listen({ host = '0.0.0.0', port = 53 } = {}) {
      if (listening) throw new Error('DNS service is already listening');
      await new Promise((resolve, reject) => {
        const onError = (error) => {
          tcp.off('listening', onListening);
          reject(error);
        };
        const onListening = () => {
          tcp.off('error', onError);
          resolve();
        };
        tcp.once('error', onError);
        tcp.once('listening', onListening);
        tcp.listen(port, host);
      });
      const actualPort = tcp.address().port;
      try {
        await new Promise((resolve, reject) => {
          const onError = (error) => {
            udp.off('listening', onListening);
            reject(error);
          };
          const onListening = () => {
            udp.off('error', onError);
            resolve();
          };
          udp.once('error', onError);
          udp.once('listening', onListening);
          udp.bind(actualPort, host);
        });
      } catch (error) {
        await new Promise((resolve) => tcp.close(resolve));
        throw error;
      }
      listening = true;
      listenAddress = { host, port: actualPort };
      logger({ type: 'listening', host, port: actualPort });
      return { ...listenAddress };
    },
    address() {
      return listenAddress ? { ...listenAddress } : null;
    },
    async close() {
      if (!listening) return;
      await Promise.all([
        new Promise((resolve) => udp.close(resolve)),
        new Promise((resolve) => tcp.close(resolve))
      ]);
      listening = false;
      listenAddress = null;
    }
  };
}

export const DNS_SERVICE_DEFAULTS = Object.freeze({
  tcpIdleTimeoutMs: DEFAULT_TCP_IDLE_TIMEOUT_MS
});
