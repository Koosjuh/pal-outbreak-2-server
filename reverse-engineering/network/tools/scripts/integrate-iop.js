'use strict';
// Split IOP module decompile dumps into per-function .c + add to functions.json (namespaced by module,
// since IOP relocatable addresses collide across modules). Module id = iop-<MODULE>.
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const SRC = path.join(ROOT, 'sources/iop-modules');
const IDX = path.join(ROOT, 'indexes');
const fns = JSON.parse(fs.readFileSync(path.join(IDX, 'functions.json'), 'utf8'));
const have = new Set(fns.map(f => f.id));

// role heuristic by module name
const roleOf = (mod) => {
  const m = mod.toUpperCase();
  if (/INETCTL/.test(m)) return 'iop-inet-control';
  if (/INET/.test(m)) return 'iop-socket';           // sceInet socket API
  if (/AVETCP/.test(m)) return 'iop-tcpip';           // Avetcp TCP/IP
  if (/AVEPPP|PPP/.test(m)) return 'iop-ppp';
  if (/DHCP/.test(m)) return 'iop-dhcp';
  if (/SMAP|DEV9/.test(m)) return 'iop-ethernet';
  if (/NETCNF/.test(m)) return 'iop-netconfig';
  if (/DEVGLUE|DVGLUE|IOPINT|WRAPE|LOADHIGH|USBSRCH/.test(m)) return 'iop-glue';
  return 'iop-other';
};

let added = 0, files = 0;
for (const dump of fs.readdirSync(SRC).filter(f => f.endsWith('-decompile.txt'))) {
  const mod = dump.replace('-decompile.txt', '');
  const role = roleOf(mod);
  const outdir = path.join(SRC, mod);
  fs.mkdirSync(outdir, { recursive: true });
  const lines = fs.readFileSync(path.join(SRC, dump), 'utf8').split(/\r?\n/);
  let cur = null, addr = null, size = null, callers = 0, callees = 0, buf = [];
  const flush = () => {
    if (!cur) return;
    const fname = `${mod}_${cur}`;                    // namespaced filename
    fs.writeFileSync(path.join(outdir, `${fname}.c`), buf.join('\n')); files++;
    const id = `iop-${mod}:${addr}`;
    if (!have.has(id)) {
      fns.push({
        id, address: addr, name: fname, resolved_name: null,
        module: `iop-${mod}`, binary: `${mod}.IRX`, subsystem: role, relevance: 'support',
        status: 'inventoried', confidence: 'unknown', size: size, callers_count: callers, callees_count: callees,
        raw_path: `sources/iop-modules/${mod}/${fname}.c`, doc_path: null,
      });
      have.add(id); added++;
    }
  };
  for (const line of lines) {
    const fm = line.match(/^FUNCTION (\S+) @ (0x[0-9a-f]+) size=(\d+)/);
    if (fm) { flush(); cur = fm[1]; addr = fm[2]; size = Number(fm[3]); callers = callees = 0; buf = [line]; continue; }
    const cm = line.match(/^CALLERS \((\d+)\)/); if (cm) callers = Number(cm[1]);
    const em = line.match(/^CALLEES \((\d+)\)/); if (em) callees = Number(em[1]);
    if (cur) buf.push(line);
  }
  flush();
}
fs.writeFileSync(path.join(IDX, 'functions.json'), JSON.stringify(fns, null, 1));
console.log(`IOP integrate: ${files} function files, ${added} added to inventory`);
