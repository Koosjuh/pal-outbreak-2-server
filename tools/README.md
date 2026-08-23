# Tools

Node.js research/runtime tooling, migrated from `C:\dnas\active\tools` and
organized by purpose. These drive the emulator (PINE), parse captures, and
inspect runtime/RAM state during protocol research.

| Folder | Purpose |
|---|---|
| `pine/` | PINE-based emulator control: dump/poke state, drive register/login flow, simulate input. |
| `disasm/` | MIPS/overlay disassembly helpers. |
| `dump/` | Memory/region/table dumpers (by address, range, overlay, marker table). |
| `extract/` | Extract data from captures, RAM, ISO regions, strings. |
| `search/` | Find/scan/xref helpers for refs, writers, markers, strings, modules. |
| `pcap/` | Packet capture analysis, diffing, replay, timeline building. |
| `runtime/` | Live runtime watchers, samplers, probes, snapshots, monitors. |
| `snap/` | SN@P lobby/room/online-gate triggers and scans. |
| `ghidra/` | Ghidra decompile/analysis runners (`.java` + `run-*.ps1`). |
| `codex/` | Codex-authored tooling (kept separate per project convention). |

These were authored against the legacy workspace; paths/addresses inside may
need adjustment for the new layout. Treat them as research tooling, not
production code.
