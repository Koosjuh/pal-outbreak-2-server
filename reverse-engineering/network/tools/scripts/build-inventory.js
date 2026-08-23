'use strict';
// Build the authoritative machine-readable master inventory functions.json from the two source inventories.
// Every function starts status=inventoried, subsystem=unclassified, confidence=unknown until a record is written.
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');           // reverse-engineering/network
const IDX = path.join(ROOT, 'indexes');
const OVL_RAW = path.join(ROOT, 'sources/overlays/overlay-3dat-decompile');
const TRN_RAW = path.join(ROOT, 'sources/executables/transport-decompile');

const fns = [];
// Overlay: addr, size, callers, callees, name, module
for (const line of fs.readFileSync(path.join(IDX, 'INVENTORY-overlay.tsv'), 'utf8').trim().split('\n')) {
  const [addr, size, callers, callees, name] = line.split('\t');
  const rawExists = fs.existsSync(path.join(OVL_RAW, `${name}.c`));
  fns.push({
    id: addr, address: addr, name, resolved_name: null,
    module: 'overlay-3dat', binary: '3.DAT', subsystem: 'unclassified',
    status: 'inventoried', confidence: 'unknown',
    size: Number(size), callers_count: Number(callers), callees_count: Number(callees),
    raw_path: rawExists ? `sources/overlays/overlay-3dat-decompile/${name}.c` : null,
    doc_path: null,
  });
}
// Transport: addr, name, module
for (const line of fs.readFileSync(path.join(IDX, 'INVENTORY-transport.tsv'), 'utf8').trim().split('\n')) {
  const [addr, name] = line.split('\t');
  const rawExists = fs.existsSync(path.join(TRN_RAW, `${name}.c`));
  fns.push({
    id: addr, address: addr, name, resolved_name: null,
    module: 'main-ee', binary: 'SLES_533.19', subsystem: 'unclassified',
    status: 'inventoried', confidence: 'unknown',
    size: null, callers_count: null, callees_count: null,
    raw_path: rawExists ? `sources/executables/transport-decompile/${name}.c` : null,
    doc_path: null,
  });
}
fns.sort((a, b) => a.address.localeCompare(b.address));
fs.writeFileSync(path.join(IDX, 'functions.json'), JSON.stringify(fns, null, 1));
const noRaw = fns.filter(f => !f.raw_path).length;
console.log(`functions.json: ${fns.length} entries (overlay=${fns.filter(f=>f.module==='overlay-3dat').length}, transport=${fns.filter(f=>f.module==='main-ee').length}); missing raw=${noRaw}`);
