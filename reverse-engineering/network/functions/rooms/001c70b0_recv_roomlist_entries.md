# 0x001c70b0 recv_roomlist_entries

| field | value |
|---|---|
| Original address | 0x001c70b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c70b0 |
| Resolved name | recv_roomlist_entries |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3a60, FUN_001c3ab0, FUN_001c3b90
**Referenced globals:** 0x3619d0 room-id-table[64]; 0x365e20 room-records; 0x365e0c write-idx; 0x365e18 received; 0x365e1e count; 0x365e0e prev-count; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x365e0c write-idx; 0x365e18 received; conn+0xd next-state

## Behavioral explanation
Reply-0x20 handler: reconciles the active-room id table (0x3619d0, 64 u16 slots), then reads a batch of room records (0x260 bytes each at 0x365e20) — name(0x3e), id(0xf), 8 flag bytes, data(0xff) — advancing 0x365e0c; loops state 0x06 until 0x365e18>=total then state 0x08.

## Notes / uncertainty
Core page ingest (op20 reply): purge shrunk ids from 0x3619d0[64], clamp list to 16, stream 0x260 records (name0x3e/id0xf/8flags/data0xff/token+0x15c) to 0x365e20; op_mode4 sums member_count(+0x158). Feeds lobby counts. op_mode-4 trigger inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c70b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
