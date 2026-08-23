#!/usr/bin/env node
/**
 * Entry point for the composed V2 server.
 *
 * Runs as an ordinary Node.js process: no native build step, no platform
 * assumptions, stdout for logs, signals for shutdown, non-zero exit on failure.
 * Under systemd that is everything a `Restart=always` unit needs - the process
 * either serves every configured endpoint or exits and gets restarted.
 *
 * Start it by hand with:
 *   node server-v2/bin/pal-server-v2.js
 * with the environment described in docs/runbooks/v2-server.md.
 */
import process from 'node:process';

import { createApplication } from '../src/app/application.js';
import { loadServerConfig } from '../src/config/server-config.js';
import { createLogger } from '../src/logging/logger.js';

async function main() {
  let config;
  let logger = createLogger({ level: 'info' });
  try {
    config = loadServerConfig(process.env);
    logger = createLogger({ level: config.logLevel });
  } catch (error) {
    logger.error('configuration-invalid', {
      error: error.message,
      problems: error.problems ?? null
    });
    process.exitCode = 78; // EX_CONFIG
    return;
  }

  logger.info('starting', {
    node: process.version,
    platform: process.platform,
    arch: process.arch,
    pid: process.pid,
    bindHost: config.bindHost,
    dataDirectory: config.dataDirectory,
    directoryFile: config.directoryFile,
    dns: config.dns.enabled ? config.dns.port : 'disabled',
    dnas: config.dnas.enabled ? config.dnas.port : 'disabled',
    http: config.http.port,
    tcp: config.tcp.port
  });

  let application;
  try {
    application = createApplication({ config, logger });
    await application.start();
  } catch (error) {
    logger.error('startup-failed', {
      error: error.message,
      code: error.code ?? null,
      listener: error.listener ?? null
    });
    process.exitCode = 1;
    return;
  }

  let stopping = false;
  const shutdown = async (signal) => {
    if (stopping) return;
    stopping = true;
    logger.info('shutdown-requested', { signal });
    try {
      await application.stop();
    } catch (error) {
      logger.error('shutdown-failed', { error: error.message });
      process.exitCode = 1;
    }
  };

  for (const signal of ['SIGINT', 'SIGTERM']) {
    process.on(signal, () => { void shutdown(signal); });
  }
  // A crash must not leave the process half-serving; stop and let systemd
  // restart it cleanly rather than continuing in an unknown state.
  process.on('uncaughtException', (error) => {
    logger.error('uncaught-exception', { error: error.message, stack: error.stack });
    process.exitCode = 1;
    void shutdown('uncaughtException');
  });
  process.on('unhandledRejection', (reason) => {
    logger.error('unhandled-rejection', { error: String(reason) });
    process.exitCode = 1;
    void shutdown('unhandledRejection');
  });
}

await main();
