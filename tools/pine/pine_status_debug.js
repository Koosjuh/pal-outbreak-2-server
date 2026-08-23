#!/usr/bin/env node
// Use PineClient directly, log every step, narrow down where it hangs.
'use strict';
const { PineClient } = require('./pine_client');

const t0 = Date.now();
const log = (msg) => console.log(`+${(Date.now()-t0).toString().padStart(4)}ms ${msg}`);

(async () => {
  log('creating client');
  const c = new PineClient({ port: 28011, timeoutMs: 8000 });

  // Hook into the raw socket once it exists by overriding _onData
  const origOnData = c._onData.bind(c);
  c._onData = (d) => {
    log(`SOCKET RECV ${d.length}B: ${d.toString('hex')}`);
    origOnData(d);
    log(`AFTER dispatch, queue.length=${c.queue.length}`);
  };

  log('calling connect()');
  await c.connect();
  log(`connected, connected=${c.connected}, sock=${c.sock ? 'yes' : 'no'}`);

  log('calling status()');
  try {
    const s = await c.status();
    log(`status returned: ${JSON.stringify(s)}`);
  } catch (e) {
    log(`status threw: ${e.message}`);
  }
  c.close();
  log('done');
})().catch(e => { log(`UNHANDLED: ${e.message} ${e.stack}`); process.exit(1); });
