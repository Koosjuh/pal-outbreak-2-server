# PAL Resident Evil Outbreak File #2 — online server

A from-scratch reimplementation of the online services for the PAL release of *Resident Evil
Outbreak File #2* (`SLES_533.19`), so an **unmodified** PAL disc on a **stock PlayStation 2** can
play online again after changing only its DNS. It pairs a Node.js private server with an
evidence-backed reverse-engineering corpus of Sega's **SN@P** network middleware and the game's
lobby/room protocol.

The official service closed in 2007, and the PAL release never had a working online service
outside Japan's Bioserver ecosystem. The hard constraint of this project: **fixes go in the
server, the protocol implementation, or the research tooling — never in the game.** No ISO
patching, no modchip, no homebrew client. The client is retail; only the server is ours.

> **New here? Start with these three:**
> 1. [`docs/PROTOCOL-SPEC-INTERNAL.md`](docs/PROTOCOL-SPEC-INTERNAL.md) — the single implementation
>    reference for the whole protocol (transport → lobby → room → game start), each claim graded by
>    evidence.
> 2. [`docs/findings/protocol/SESSION-LOG-2026-08-24.md`](docs/findings/protocol/SESSION-LOG-2026-08-24.md)
>    — the blow-by-blow of how multiplayer was brought up, with the wire/decompile/memory evidence.
> 3. [`reverse-engineering/network/BUILD_GUIDE.md`](reverse-engineering/network/BUILD_GUIDE.md) —
>    how to turn the decompiled corpus into server behaviour.

---

## Current status

**Two players can start a game together.** As of the 2026-08-25 session, both a real PS2 and a
PCSX2 client sign in, select server and area, create/join a room, pick scenario and characters, and
**both load into the same game with player movement syncing between consoles** — the core milestone
the project was built to reach.

What works, rig-confirmed:

- DNAS authentication, sign-in, server/area selection (all ten areas), lobby entry, room lists.
- Room creation and joining; the seating/accept handshake that admits a joiner and starts a
  non-solo game.
- Rules, cast, and scenario selectable on the create screen; the joiner sees the room's real
  scenario.
- Backing out of a room (the long-standing "Exit" freeze is fixed).
- In-game player-movement relay between consoles.

Active frontier (the "fully playable" work):

- **In-game entity sync** — the netcode is peer-indexed *lockstep-deterministic*; enemies are
  client-local, so both consoles must run identical simulations. Making that robust means a
  **lossless game-packet relay** (a higher-latency console currently drops packets) and completing
  the **character (charstats) hand-off in both directions**. See
  [`analysis/ingame-receive-stack-RE-2026-08-25.md`](analysis/ingame-receive-stack-RE-2026-08-25.md)
  and [`docs/design/v2-port/INGAME-PACKET-GAPLIST-2026-08-25.md`](docs/design/v2-port/INGAME-PACKET-GAPLIST-2026-08-25.md).
- Lobby polish: player counts, in-room member list, room chat rendering, end-screen character.

Development centres on [`server-v2/`](server-v2/), a corpus-driven port of the Japanese Bioserver's
session/room architecture onto the PAL SN@P transport, with a large deterministic test suite.
[`server/`](server/) is the older v1 server. The rig is a Raspberry Pi acting as server and local
DNS target, with a real PS2 and PCSX2 as clients; PCSX2 is used for repeatable memory tracing via
PINE, and real hardware for final validation.

SN@P was shared by other games of the period and is barely documented publicly, so the transport
notes and decoded client code here may help work on other SN@P-era titles too.

---

## The project in three layers

1. **The server** ([`server-v2/`](server-v2/)) — Node.js services that speak the game's DNS, DNAS,
   HTTP, TCP-10127 lobby, and SN@P/UDP protocols. Behaviour is turned on in evidence-backed vertical
   slices, each behind an environment flag so it can be rolled back independently.
2. **The corpus** ([`reverse-engineering/`](reverse-engineering/)) — the decompiled, annotated
   client-network code that tells the server what the game expects. This is the source of truth; the
   server is downstream of it.
3. **The findings** ([`docs/`](docs/), [`analysis/`](analysis/)) — the specs, protocol write-ups,
   and session logs that connect wire captures and decompiles to server decisions.

---

## Setting up server v2

**Requirements:** Node.js **22.5+** (persistence uses the built-in `node:sqlite`; on 22.5–22.12 it
needs `--experimental-sqlite`, unflagged from 22.13 / 23.4). No third-party runtime dependencies,
no build step.

### 1. Run the test suite (no game needed)

```sh
git clone https://github.com/Koosjuh/pal-outbreak-2-server
cd pal-outbreak-2-server/server-v2
node --version      # must be >= 22.5
npm test            # deterministic suite; proves the protocol codecs and state machines
```

### 2. Start the server for a local PCSX2 run (lobby only, DNS/DNAS off)

The simplest bring-up points the emulator straight at the host and disables the parts that need
certificates and privileged ports. Replace `192.168.2.121` with the address your client will dial.

```sh
PAL_V2_MASTER_KEY="$(openssl rand -base64 32)" \
PAL_V2_DATA_DIR=./.v2-data \
PAL_V2_SELF_HOST=192.168.2.121 \
PAL_V2_SNAP_HOST=192.168.2.121 \
PAL_V2_DIRECTORY_FILE=server-v2/config/directory.example.json \
PAL_V2_LOBBY_NAME='PAL V2' \
PAL_V2_ENABLE_DNS=false \
PAL_V2_ENABLE_DNAS=false \
PAL_V2_LOG_LEVEL=debug \
node server-v2/bin/pal-server-v2.js
```

Copy `server-v2/config/directory.example.json` somewhere writable and edit it before serving
anything real — its `provenance` must be `operator` (a `test-fixture` file is refused by design).

### 3. Full network service (real disc, DNS + DNAS)

For a real PS2 (or a full PCSX2 flow), the server also serves DNS and the DNAS TLS/application
exchange, which needs operator-provided certificates and the standard ports:

```sh
PAL_V2_MASTER_KEY="$(openssl rand -base64 32)" \
PAL_V2_DATA_DIR=/var/lib/pal-server-v2 \
PAL_V2_SELF_HOST=<your-server-ip> \
PAL_V2_SNAP_HOST=<your-server-ip> \
PAL_V2_DIRECTORY_FILE=/etc/pal-server-v2/directory.json \
PAL_V2_LOBBY_NAME='PAL V2' \
PAL_V2_DNS_RECORDS='snap01.capcom.client.sf.yav4.com=<your-server-ip>' \
PAL_V2_DNAS_CERT=/etc/pal-server-v2/dnas/server.crt \
PAL_V2_DNAS_CA_CERT=/etc/pal-server-v2/dnas/ca.crt \
PAL_V2_DNAS_KEY=/etc/pal-server-v2/dnas/server.key \
PAL_V2_DNAS_PACKET_DIR=/etc/pal-server-v2/dnas/packets \
node server-v2/bin/pal-server-v2.js
```

Then point the console's DNS at the server (see [DNS records](#dns-records) below) and boot the
game — it follows its normal connection flow to your server.

**Key notes**

- Generate `PAL_V2_MASTER_KEY` **once and keep it** — it seals stored account secrets at rest;
  losing it loses them. It never belongs in the repo.
- `PAL_V2_UDP_BIND_ADDRESS` must be the exact IPv4 the client dials — the client discards SN@P
  datagrams whose source address doesn't match, so a `0.0.0.0` bind on a multi-homed host presents
  as broken crypto.
- Behaviour flags (e.g. `SNAP_GAME_RELAY`, `SNAP_ROOM_STAT`, `SNAP_HOST_RESEAT`,
  `SNAP_RELIABLE_WINDOW`) toggle individual protocol fixes; every one lists its default and rollback
  in [`docs/runbooks/v2-server.md`](docs/runbooks/v2-server.md).

Full configuration, the systemd unit, and startup/shutdown behaviour:
[`docs/runbooks/v2-server.md`](docs/runbooks/v2-server.md). Architecture and the evidence policy:
[`server-v2/ARCHITECTURE.md`](server-v2/ARCHITECTURE.md). Raspberry Pi deployment:
[`docs/runbooks/pi-deployment.md`](docs/runbooks/pi-deployment.md) and
[`scripts/deploy-pi.ps1`](scripts/deploy-pi.ps1).

---

## The reverse-engineering corpus — what it is and how to use it

[`reverse-engineering/`](reverse-engineering/) is the heart of the project: an evidence-backed,
navigable decompilation of the retail client's networking code. It is **not** a dump of raw Ghidra
output — it is a curated library where the networking functions of the game's main executable and
overlays have been decoded, named, and cross-referenced, so a server author can answer "what does
the client expect here?" without re-deriving it.

### What's in it

Under [`reverse-engineering/network/`](reverse-engineering/network/):

| Entry point | What it gives you |
|---|---|
| [`README.md`](reverse-engineering/network/README.md) | Orientation and conventions. |
| [`MASTER_INDEX.md`](reverse-engineering/network/MASTER_INDEX.md) | The top-level index of everything. |
| [`SUBSYSTEM_MAP.md`](reverse-engineering/network/SUBSYSTEM_MAP.md) | How the networking splits into subsystems (transport, lobby, rooms, roster, chat, session, menus…). |
| [`BUILD_GUIDE.md`](reverse-engineering/network/BUILD_GUIDE.md) | **The bridge from corpus to server:** for each multiplayer flow, the exact message sequence the client drives and what the server must send/expect. |
| [`library/`](reverse-engineering/network/library/) | One Markdown "volume" per subsystem — readable prose plus decompile excerpts. |
| [`functions/<subsystem>/<addr>_<name>.md`](reverse-engineering/network/functions/) | One note per decoded function: address, callers/callees, referenced globals/opcodes, a behavioural explanation, a confidence grade, and the raw decompile. |
| [`indexes/`](reverse-engineering/network/indexes/) | Machine-readable indexes — `functions.json`, `subcommands.json`, `opcodes_seen.json`, the opcode↔name map, cross-references, structure layouts. |

### How to use it

- **"What handles opcode 0x??"** — check the packet/subcommand indexes or
  [`indexes/OPCODE-NAME-MAP.md`](reverse-engineering/network/indexes/OPCODE-NAME-MAP.md), then open
  the named function note.
- **"How do I implement flow X on the server?"** — start in `BUILD_GUIDE.md`; it names the client
  functions that prove each step and the bytes the server owes.
- **"What does function `FUN_00xxxxxx` do?"** — open its note under `functions/`; each links its
  callers, callees, and the globals/opcodes it touches.
- **Programmatic queries** — the JSON files in `indexes/` are built for scripting (grep, `jq`, or
  the tooling in [`tools/`](tools/)).

### Read the confidence grade

Every claim carries an evidence grade — runtime-observed and decompile-confirmed findings are the
safe foundation; anything marked inference/hypothesis needs verification before code relies on it.
The project's standard (`docs/CORPUS-METHODOLOGY.md`) is explicit that the cross-reference tooling is
a *discovery* mechanism, not a proof of absence: "the only caller", "unreachable", and "exactly N"
require control-flow-aware checks (including MIPS delay slots) before they become fact. When you find
a better explanation, correct the note, mark the old conclusion superseded, and leave the trail
intact.

---

## Repository layout

| Path | Contents |
|---|---|
| [`server-v2/`](server-v2/) | Current server: composed Node.js services, state model, protocol code, tests. |
| [`server/`](server/) | The older v1 server. |
| [`reverse-engineering/`](reverse-engineering/) | The decoded client-network corpus (9,000+ files: function notes, indexes, source exports, build guidance). |
| [`docs/`](docs/) | Protocol findings, specifications, design records, runbooks, and the internal protocol spec. |
| [`analysis/`](analysis/) | Focused reverse-engineering write-ups for specific mechanisms. |
| [`tools/`](tools/) | PINE, packet-analysis, runtime-inspection, Ghidra, Wireshark, and rig utilities. |
| [`scripts/`](scripts/), [`deploy/`](deploy/) | Raspberry Pi deployment scripts and service configuration. |
| [`.claude/`](.claude/), [`CLAUDE.md`](CLAUDE.md), [`AGENTS.md`](AGENTS.md) | Operating material for the owner's AI-assisted research sessions — not contributor prerequisites. |

Local-only assets (the game ISO, extracted binaries, reference server source, Ghidra databases,
raw captures) are intentionally **not** in the repository; see [Provenance](#provenance).

---

## Contributing

Help is welcome from PS2/MIPS reverse engineers, Node.js and protocol developers, and testers with
original hardware.

**Good first areas**

- **Server implementation** — `server-v2/` has testable vertical slices; the in-game entity sync,
  the charstats hand-off, and the lobby-polish items (counts, member list, chat) are all
  well-scoped. Read `docs/PROTOCOL-SPEC-INTERNAL.md` first.
- **Reverse engineering** — the game-engine (non-network) functions that consume received game
  packets are not yet decoded; the corpus methodology and the network corpus show the house style.
- **Testing** — reliable two-console runs on real PS2s are especially valuable; the session logs
  show the capture/PINE method used.

**What you need to build/test the full system** (none of it is distributable here):

- A disc image dumped from **your own** PAL File #2 disc.
- PCSX2 with **PINE enabled** (for memory tracing), or a real PS2, plus a local DNS setup.
- Ghidra with the game binary imported, for deeper client analysis.
- The Japanese Bioserver reference source, available from a maintainer where it can be shared
  appropriately. openSNAP (an independent SN@P server) is public and cross-referenced in
  [`docs/findings/protocol/OPENSNAP-CROSSREF-2026-08-24.md`](docs/findings/protocol/OPENSNAP-CROSSREF-2026-08-24.md).

### DNS records

Point the console's DNS at your server so the game resolves its service hostnames to you:

| Hostname | Type | Value |
|---|---|---|
| `gate1.eu.dnas.playstation.org` | A | `<your-server-ip>` |
| `app01.reo.capcom.sf.yav4.com` | A | `<your-server-ip>` |
| `snap01.capcom.client.sf.yav4.com` | A | `<your-server-ip>` |
| `*.yav4.com` | A | `<your-server-ip>` |
| `stage6.sega.com` | A | `<your-server-ip>` |
| `regweb.reo.capcom.sf.yav4.com` | A | `<your-server-ip>` |

---

## Acknowledgements

Built with heavy AI assistance from Claude (Anthropic) and Codex (OpenAI) for Ghidra analysis, PINE
and packet tooling, protocol review, implementation, and test loops. The project owner directs the
work and validates milestones on hardware. The AI-session workflow is documented in `CLAUDE.md` and
`AGENTS.md` for the curious; contributors are **not** expected to use AI or follow those
session-specific documents.

## Provenance

This repository is a curated export from a larger private working archive. Raw captures, copyrighted
binaries, the reference server, large tool databases, and month-by-month session history remain in
that archive. Some historical documents keep references to those materials so their evidence trail
is not silently rewritten — ask a maintainer when a missing archive item is needed for a specific
investigation.
