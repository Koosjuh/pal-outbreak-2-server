import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
const repositoryRoot = path.resolve(here, '..', '..');

function read(relativePath) {
  return fs.readFileSync(path.join(repositoryRoot, relativePath), 'utf8');
}

function hex(value, width = 2) {
  return `0x${value.toString(16).padStart(width, '0')}`;
}

function corpusOpcodes(markdown) {
  const result = new Map();
  for (const line of markdown.split(/\r?\n/)) {
    const match = line.match(
      /^\| `0x([0-9a-f]+)` \| ([^|]+) \| ([^|]*) \| ([^|]*) \| ([^|]*) \| (\d+) \|$/i
    );
    if (!match) continue;
    const opcode = Number.parseInt(match[1], 16);
    result.set(opcode, {
      opcode,
      direction: match[2].trim(),
      builders: match[3].trim(),
      parsers: match[4].trim(),
      dispatcher: match[5].trim(),
      functionCount: Number.parseInt(match[6], 10)
    });
  }
  return result;
}

function udpOpcodeReferences(source) {
  const result = new Set();
  const patterns = [
    /msg\[3\]\s*={2,3}\s*0x([0-9a-f]+)/gi,
    /msg\[3\]\s*>?=\s*0x([0-9a-f]+)/gi,
    /msg\[3\]\s*<=\s*0x([0-9a-f]+)/gi,
    /lo\s*={2,3}\s*0x([0-9a-f]+)/gi
  ];
  for (const pattern of patterns) {
    for (const match of source.matchAll(pattern)) {
      result.add(Number.parseInt(match[1], 16));
    }
  }
  return result;
}

function snapTcpCommands(source) {
  const objectMatch = source.match(/const CMD = \{([\s\S]*?)\n\};/);
  if (!objectMatch) throw new Error('cannot locate V1 TCP CMD object');

  const commands = new Map();
  for (const match of objectMatch[1].matchAll(/^\s*([A-Z0-9_]+)\s*:\s*0x([0-9a-f]+)/gim)) {
    commands.set(match[1], Number.parseInt(match[2], 16));
  }

  const handlers = new Set();
  for (const match of source.matchAll(/\[CMD\.([A-Z0-9_]+)\]\s*:/g)) {
    handlers.add(match[1]);
  }
  return { commands, handlers };
}

function environmentFlags(source) {
  return [
    ...new Set([...source.matchAll(/process\.env\.(SNAP_[A-Z0-9_]+)/g)].map((match) => match[1]))
  ].sort();
}

function markdownReport() {
  const packetIndex = corpusOpcodes(
    read('reverse-engineering/network/protocols/PACKET_INDEX.md')
  );
  const udpSource = read('server/game_udp_server.js');
  const udpReferences = udpOpcodeReferences(udpSource);
  const tcpSource = read('server/snap_server.js');
  const { commands, handlers } = snapTcpCommands(tcpSource);
  const flags = environmentFlags(`${udpSource}\n${tcpSource}`);

  const corpusMissingFromV1Conditions = [...packetIndex.values()].filter(
    ({ opcode }) => !udpReferences.has(opcode)
  );
  const v1ConditionWithoutCorpusIndex = [...udpReferences].filter(
    (opcode) => !packetIndex.has(opcode)
  );
  const tcpDeclaredWithoutHandler = [...commands.entries()].filter(
    ([name]) => !handlers.has(name)
  );

  const lines = [
    '# Generated V1 versus corpus coverage summary',
    '',
    '> This is a lexical coverage audit, not proof that a referenced handler is correct. An opcode',
    '> appearing in a V1 condition still requires byte-layout, state, and runtime validation.',
    '',
    `- Corpus application opcodes: ${packetIndex.size}`,
    `- V1 UDP opcodes explicitly referenced by source conditions: ${udpReferences.size}`,
    `- Corpus opcodes absent from explicit V1 UDP conditions: ${corpusMissingFromV1Conditions.length}`,
    `- V1 conditional opcode values absent from PACKET_INDEX: ${v1ConditionWithoutCorpusIndex.length}`,
    `- V1 TCP commands declared: ${commands.size}`,
    `- V1 TCP commands with handlers: ${handlers.size}`,
    `- V1 TCP commands declared without handlers: ${tcpDeclaredWithoutHandler.length}`,
    `- V1 SNAP_* behavior flags across TCP/UDP: ${flags.length}`,
    '',
    '## Corpus opcodes absent from explicit V1 UDP conditions',
    '',
    '| Opcode | Corpus direction | Corpus functions |',
    '|---:|---|---:|',
    ...corpusMissingFromV1Conditions.map(
      (entry) => `| ${hex(entry.opcode)} | ${entry.direction} | ${entry.functionCount} |`
    ),
    '',
    '## V1 UDP opcode conditions',
    '',
    [...udpReferences].sort((a, b) => a - b).map((opcode) => hex(opcode)).join(', '),
    '',
    '## V1 TCP commands declared without a handler',
    '',
    '| Symbol | Command |',
    '|---|---:|',
    ...tcpDeclaredWithoutHandler.map(([name, command]) => `| ${name} | ${hex(command, 4)} |`),
    '',
    '## V1 experimental/configuration surface',
    '',
    ...flags.map((flag) => `- \`${flag}\``),
    ''
  ];
  return lines.join('\n');
}

process.stdout.write(markdownReport());

