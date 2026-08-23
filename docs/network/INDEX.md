# PAL client-network evidence map

Date: 2026-07-28
Target: Resident Evil Outbreak File #2 PAL, `SLES_533.19`
Audit commit basis: `e2ba1a9315639a5a0f10dc45c8741959009f7b2d`

This directory is the evidence-led index for the original PAL client protocol and
the current private-server implementation. It does not replace raw decompiler
exports, packet captures, session logs, or `FACTS.md`; it maps and classifies them.
Generated `FUN_*` names are address labels, not authoritative names.

## Confidence vocabulary

| Label | Meaning |
|---|---|
| `Decoded` | Verified from PAL client reads, writes, comparisons, branches, or call sites. |
| `Runtime` | Verified from a packet capture, PINE/runtime trace, journal, or witnessed client behavior. |
| `Both` | Independently supported by decoded PAL code and runtime evidence. |
| `Probable` | Strong interpretation, but a decisive client trace or code path is missing. |
| `Unknown` | Evidence is insufficient or contradictory. |

These labels are intentionally narrower than natural-language words such as
“working” or “implemented.” A server handler can exist while its PAL meaning is
still `Unknown`.

## Evidence map

| Subject | Canonical repository location | What is there | Authority |
|---|---|---|---|
| Controlling project model | `CLAUDE.md`, `GOALS.md`, `FACTS.md`, `GOLDENS.md` | Operating rules, active goal, durable technical model, reproducible golden states | Highest for current project status; `FACTS.md` and `GOALS.md` stop before the July 25–26 breakthrough, so use the session log below for that delta. |
| Raw main-ELF and module exports | `exports/ghidra/` | 109 tracked disassembly/decompiler/caller/global exports | Primary static evidence when the program/module and address are stated. |
| Interpreted reverse engineering | `analysis/` | 160 focused call graphs, structure notes, full-module dumps, and July 25–26 investigations | Secondary to raw exports/disassembly; confidence varies per file. |
| Lobby/room overlay full decode | `analysis/claude-helper-module-full-2026-05-29.txt` | Large decoded `3.DAT`/`netwk.bin` function corpus | Primary decompiler output for overlay functions, but critical conclusions still require disassembly/runtime checks. |
| In-game overlay full decode | `analysis/claude-game-module-full-2026-05-29.txt` | Large decoded `2.DAT`/`game.bin` corpus, including `nbSendPlayerOther` paths | Primary decompiler output; no PAL gameplay wire specification has yet been derived from it. |
| Main SN@P transport map | `analysis/snap-module-map.md`, `analysis/snap-focused-callgraph.md`, `analysis/snap-packet-struct.md` | Main-ELF/IRX boundary, receive/send graph, packet-object offsets | Useful foundation; May-era unresolved items are superseded by later L1 and July 26 transport RE. |
| Overlay/module inventory | `docs/findings/protocol/_archive/RE-overlays-2026-06-15.md`, `docs/_archive/reverse-engineering/ISO-MODULE-INVENTORY-2026-06-15.md` | Code-overlay roles, load addresses, IRX inventory | Static inventory remains useful. Its “TODO” status is historical and must not be read as current completion status. |
| Address/function inventory | `docs/_archive/reverse-engineering/evidence/function-index.md` | Main ELF and `3.DAT` function/address map | Provenance index only; several role labels are stale or too strong. |
| Transport specification | `docs/specs/L1-snap-transport-spec.md` | Header, trailer, crypto boundary, ACKs, pools, retries | Authoritative through its 2026-07-02 validation, with ordered-receive details superseded by `analysis/op06-accept-criterion-RE-2026-07-26.txt`. |
| Application notes | `docs/specs/L3-app-protocol-spec.md`, `docs/findings/protocol/` | Opcode/layout notes and live experiment logs | Per-claim authority only. L3 is dated 2026-07-02 and contains conclusions later corrected. |
| Latest live finding | `docs/findings/protocol/SESSION-LOG-2026-07-25.md` | T1–T13 create/roster experiments; T13 proves op06 delivery and client-memory population | Current runtime authority for the July 25–26 work. |
| Curated wire/runtime evidence | `docs/evidence/` | Tracked pcaps, traces, screenshots, HTTP captures, and manifest | Primary runtime evidence when platform/provenance are stated. |
| Additional working captures | `captures/` | Savestates, PINE samples, join-window packet notes | Primary or supporting evidence per artifact; do not merge emulator and hardware observations. |
| Harness outputs | `tests/results/` | Ignored local runs, pcaps, journals, PINE samples, screenshots | Local evidence only unless promoted into tracked evidence. The latest three directories lack `meta.json`, so they are incomplete harness records under current rules. |
| Harness and fixtures | `tests/`, `server/*.test.*` | Capture runner, watch files, transport simulation, state/engine/wire tests | Reproducible local evidence for code behavior, not proof that the PAL client accepts a flow. |
| Current server | `server/` | DNS, HTTP/DNAS, TCP 10127, UDP 9090, state model and optional lobby engine | Implementation under audit. |
| Tracked runtime configuration | `deploy/pal-server.service.d/00-pal-server.conf` | Consolidated feature flags as of 2026-07-13 | Repository configuration evidence, not proof of the current Pi effective environment. |
| KDDI reference | `docs/spec/kddi-reference-spec.md`, `references/bioserver2/` when locally present | Reference-server lifecycle and command intent | Structural intent only; never PAL wire truth. |
| Historical documents | `archive/`, `docs/_archive/`, `docs/findings/protocol/_archive/` | Preserved investigations, rejected theories, old handoffs | Provenance only unless a current document explicitly re-validates a claim. |

Repository counts observed during this audit: 160 files under `analysis/`, 109 under
`exports/ghidra/`, 202 under `docs/findings/protocol/`, 84 under
`docs/evidence/`, and 141 under `archive/`. The evidence manifest explains which
large legacy dumps and logs were deliberately not migrated
(`docs/evidence/MANIFEST.md:1-34`).

## Program and module map

| Program/module | Base/load address | Client role | Evidence |
|---|---:|---|---|
| `SLES_533.19` main EE ELF | `0x00100000` | TCP 10127 framing/dispatch; UDP SN@P transport, registration, crypto, socket lifecycle | `docs/_archive/reverse-engineering/evidence/function-index.md:6-9`; `analysis/snap-module-map.md:33-64` |
| `BIN/3.DAT`, embedded `netwk.bin` | `0x005ac300` | Server select, area/lobby/room UI and state machines; room/game-channel callbacks | `docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:19-46,95-101` |
| `BIN/2.DAT`, embedded `game.bin` | `0x005ac300` | In-game scenario and synchronization code operating on an established connection | `docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:25-35,70-76` |
| `BIN/4.DAT`, `netdnas.bin` | `0x011c0000` | DNAS authentication | `docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:31-33` |
| `BIN/5.DAT`, `nethttp.bin` | `0x011c0000` | HTTP/SSL pre-lobby client | `docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:31-33` |
| `BIN/9.DAT`, `netaq.bin` | `0x007dba00` | IOP network-stack acquisition/loader | `docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:34-35,78-82` |
| `SNIOPINT.IRX` | IOP module | AVE-TCP EE↔IOP interface | `analysis/snap-module-map.md:137-160` |
| `SNAVETCP.IRX` / `AVETCP.IRX` | IOP modules | Generic AVE-TCP UDP/TCP implementation | `analysis/snap-module-map.md:147-160` |
| `NTGUI.ELF` | separate EE executable | Network adapter/account setup UI | `docs/_archive/reverse-engineering/ISO-MODULE-INVENTORY-2026-06-15.md:9-18` |

The `3.DAT` and `2.DAT` overlays share the same load slot, so an address in
`0x005ac300...` is not self-identifying. Every cited overlay function in this
audit states whether it comes from `netwk.bin` or `game.bin`.

## Document authority audit

| Document/group | Assessment on 2026-07-28 |
|---|---|
| `CLAUDE.md` | Authoritative operating procedure. |
| `FACTS.md` “CURRENT MODEL” | Authoritative durable model through 2026-07-17; supplement with the July 25 session log and July 26 RE. |
| `GOLDENS.md` | Authoritative record of actually witnessed/recoverable milestones. HEAD is not a golden. |
| `docs/findings/protocol/SESSION-LOG-2026-07-25.md` | Authoritative live log for the latest tested change through T13. |
| `analysis/op06-accept-criterion-RE-2026-07-26.txt` | Current static explanation for reliable inbound acceptance; its leading hypothesis was runtime-confirmed by T13. |
| `README.md` | Outdated: describes successful login as the milestone, substantially behind current room work. |
| `docs/current-status.md` | Outdated before this audit; its older timeline remains historical. |
| `docs/open-questions.md`, `docs/blocking-issues.md` | Partly outdated/incomplete; use the new evidence register and gap analysis for current scope. |
| `docs/test-plan.md` | Useful test IDs, but several expected results remain `TBD`; not proof of feature completion. |
| `docs/specs/L1-snap-transport-spec.md` | Strong transport source, but its §§3.2/4.2/5.2 “hypothesis” status is superseded in part by July 26 RE/runtime. |
| `docs/specs/L3-app-protocol-spec.md` | Historical application-layer snapshot. It predates successful room creation and contains obsolete “scenario null” and op41 interpretations. |
| `docs/spec/*` | High-value July 18–19 synthesis and KDDI comparison; conclusions requiring PAL wire mapping remain hypotheses. |
| Archived handoffs/findings | Preserve for provenance and rejected-theory control; never promote a claim solely because it appears in an archive. |

## Navigation

- [Current V2 implementation handoff](../../handoff/V2_IMPLEMENTATION_HANDOFF_2026-08-02.md) — exact
  proof boundary, repeatable corpus-to-code process, end goal, and reversible deployment/capture loop.
- [Client network architecture](CLIENT_NETWORK_ARCHITECTURE.md)
- [Protocol specification](PROTOCOL_SPECIFICATION.md)
- [Opcode matrix](OPCODE_MATRIX.md)
- [Client state machine](CLIENT_STATE_MACHINE.md)
- [Server gap analysis](SERVER_GAP_ANALYSIS.md)
- [Evidence register](EVIDENCE_REGISTER.md)
- [Implementation plan](IMPLEMENTATION_PLAN.md)
