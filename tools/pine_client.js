// Compat shim. server/snap_server.js + server/game_udp_server.js do
// `require('../tools/pine_client')`, but the implementation lives at tools/pine/pine_client.js
// (the require path predates the 2026-06-07 tools/ reorg). This 1-line re-export lets the server
// BOOT without editing any server/*.js file — preserving Pi-deploy md5 parity. Boot-critical:
// without it snap_server.js/game_udp_server.js throw MODULE_NOT_FOUND and the stack won't start.
module.exports = require('./pine/pine_client');
