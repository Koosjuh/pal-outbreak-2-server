# 0x001e1d88 blockpool_write_sentinel

| field | value |
|---|---|
| Original address | 0x001e1d88 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1d88 |
| Resolved name | blockpool_write_sentinel |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec, FUN_001e1dd0
**Callees:** —
**Referenced globals:** 0x36d758 arena base; 0x36d75c arena size hdr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Writes the free-block sentinel (size 0xcb18, magic 0xfafafafa) at the head of the 52000-byte allocator arena.

## Notes / uncertainty
Writes initial free-block header at arena 0x36d758: magic 0xfafafafa(free), size 0xcb18 (=52000-8). 8-byte hdr {magic,size}; allocated magic 0xfbfbfbfb (from FUN_001e1e4c). Confirmed against allocator+freer.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1d88.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
