'use strict';

// Run-ID: a single timestamp shared across all server modules.
// Set at first require() and cached by Node's module loader for the lifetime
// of the process. Use as a filename prefix to keep per-run logs separate.
//
// Format: YYYY_MM_DD_HH_MM_SS

const d = new Date();
const pad = n => String(n).padStart(2, '0');
const RUN_ID = `${d.getFullYear()}_${pad(d.getMonth() + 1)}_${pad(d.getDate())}_${pad(d.getHours())}_${pad(d.getMinutes())}_${pad(d.getSeconds())}`;

module.exports = { RUN_ID };
