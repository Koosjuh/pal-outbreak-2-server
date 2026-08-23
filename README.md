# PAL Resident Evil Outbreak File #2 online server

This project is rebuilding the online services used by the PAL release of *Resident Evil
Outbreak File #2* (`SLES_533.19`). It combines a Node.js private server with an evidence-backed
reverse-engineering corpus for Sega's SN@P middleware and the game's lobby protocol.

The official service closed in 2007, and the PAL release did not have a working online service
outside the Japanese Bioserver ecosystem. The aim here is to reproduce the server side closely
enough that an original PAL disc can connect from an unmodified PlayStation 2 after changing only
its DNS configuration.

That constraint is firm: fixes belong in the server, protocol implementation, or research tooling.
The project does not patch the game, modify an ISO, or require a modchip or homebrew client.

The goal is to create a working game, I own the PAL version however both the PAL and NTSC version use SN@P.

## Current status

The established v1 server has been exercised end to end on both PCSX2 and a real PS2. The verified
path includes DNAS authentication, sign-in, server and area selection, all ten areas, lobby entry,
room lists, room creation, and reaching in-room state. It is still an incomplete multiplayer
service: consistent multi-console membership, room state, chat, ready/start handling, and gameplay
networking remain active work.

Development is now centred on [`server-v2/`](server-v2/), a corpus-driven Node.js implementation
that ports the Japanese Bioserver's session and room architecture onto the PAL SN@P transport. It
has a substantial deterministic test suite, but it has not replaced v1 on the Raspberry Pi and is
not yet a complete real-client lobby server. [`GOALS.md`](GOALS.md) tracks the current work and
[`FACTS.md`](FACTS.md) records the confirmed protocol model. The detailed v2 limitations are listed
in [`docs/runbooks/v2-server.md`](docs/runbooks/v2-server.md).

The development rig uses a Raspberry Pi as the server and local DNS target, with both a real PS2
and PCSX2 clients. PCSX2 is useful for repeatable memory tracing through PINE; real hardware is
tested separately and remains necessary for final validation. In both cases, local DNS resolves
the original DNAS and SN@P hostnames to the Pi so the game follows its normal connection flow.

SN@P was shared by other games of the period and has little public documentation. Although this
repository is focused on PAL File #2, the transport notes, executable packet specifications, and
decoded client code may also help work on other SN@P-era titles.

## Repository layout

| Path | Contents |
|---|---|
| [`server-v2/`](server-v2/) | Current server development: composed Node.js services, state model, protocol code, and tests. |
| [`server/`](server/) | The v1 compatibility server currently used on the Raspberry Pi. |
| [`reverse-engineering/`](reverse-engineering/) | The decoded client-network corpus: more than 3,000 function notes, indexes, source exports, and build guidance. |
| [`docs/`](docs/) | Protocol findings, network specifications, design records, runbooks, and curated evidence. |
| [`tools/`](tools/) | PINE, packet-analysis, runtime-inspection, Ghidra, Wireshark, and rig utilities. |
| [`scripts/`](scripts/) and [`deploy/`](deploy/) | Raspberry Pi deployment scripts and service configuration. |
| [`binaries/`](binaries/), [`references/`](references/), and [`ghidra-projects/`](ghidra-projects/) | Tracked explanations for local-only game assets, reference material, and Ghidra databases. Their contents are intentionally ignored. |
| [`.claude/`](.claude/), [`CLAUDE.md`](CLAUDE.md), and [`AGENTS.md`](AGENTS.md) | Operating material for the owner's AI-assisted research sessions. These are not prerequisites or contributor instructions. |

For an orientation to the protocol material, start with
[`docs/network/INDEX.md`](docs/network/INDEX.md) and
[`server-v2/ARCHITECTURE.md`](server-v2/ARCHITECTURE.md).

## Getting started

The v2 server requires Node.js 22.5 or newer. It has no third-party runtime dependencies or build
step, so a clean checkout can run its test suite directly:

```sh
git clone <repository-url>
cd pal-outbreak-2/server-v2
node --version
npm test
```

To start v2 locally, follow [`docs/runbooks/v2-server.md`](docs/runbooks/v2-server.md). The runbook
documents the required environment variables, writable SQLite data directory, operator-authored
directory file, and a local mode with DNS and DNAS disabled. Running the complete network service
also requires operator-provided DNAS certificates and replay data, and binding the standard DNS,
HTTP, and TLS ports may require additional OS permissions. The v1 startup notes are in
[`server/README.md`](server/README.md).

Work involving the game or the full rig needs assets that cannot be distributed in this repository:

- a disc image dumped from your own PAL File #2 disc, kept under
  `binaries/original/disc-image/original/`;
- PCSX2 with PINE enabled, or a real PS2 and a suitable local DNS setup;
- Ghidra and a locally imported game binary for deeper client analysis;
- the Japanese Bioserver reference source under `references/`, available from a maintainer where it
  can be shared appropriately.

See [`docs/decisions/ADR-0003-local-binary-assets.md`](docs/decisions/ADR-0003-local-binary-assets.md)
and the README in each placeholder directory for the expected local layout. Raspberry Pi deployment
uses `PAL_PI_USER`, `PAL_PI_HOST`, `PAL_PI_SSH_KEY`, and `PAL_PI_DST`; the procedure is documented in
[`docs/runbooks/pi-deployment.md`](docs/runbooks/pi-deployment.md) and
[`scripts/deploy-pi.ps1`](scripts/deploy-pi.ps1).

## Contributing

Help is welcome from PS2/MIPS reverse engineers, Node.js and protocol developers, and testers with
original hardware. The join state machine, room protocol, and gameplay networking still need RE
work; the v2 server has testable vertical slices for implementation work; and reliable two-console
testing on real PS2s is particularly valuable.

### DNS Records

| Hostname | Type | Value | TTL |
  |---|---|---|---|
  | `gate1.eu.dnas.playstation.org` | A | `<your-server-ip>` | Auto |
  | `app01.reo.capcom.sf.yav4.com` | A | `<your-server-ip>` | Auto |
  | `snap01.capcom.client.sf.yav4.com` | A | `<your-server-ip>` | Auto |
  | `*.yav4.com` | A | `<your-server-ip>` | Auto |
  | `stage6.sega.com` | A | `<your-server-ip>` | Auto |
  | `regweb.reo.capcom.sf.yav4.com` | A | `<your-server-ip>` | Auto |****

## Acknowledgements

This project has been built with heavy AI assistance from Claude (Anthropic) and Codex (OpenAI),
used for Ghidra analysis, PINE and packet tooling, protocol review, implementation, and test loops.
The project owner directs the work and validates milestones on the hardware. The AI-session workflow
is documented in `CLAUDE.md` and `AGENTS.md` for anyone interested in how that work is organised;
contributors are not expected to use AI or follow those session-specific operating documents.

## Provenance

This repository is a curated export, made on 2026-08-23, from a larger private working archive. Raw
captures, copyrighted binaries, the reference server, large tool databases, month-by-month session
history, and scratch analysis remain in that archive. Some historical documents retain references
to those materials so that their evidence trail is not silently rewritten; ask a maintainer when a
missing archive item is needed for a specific investigation.
