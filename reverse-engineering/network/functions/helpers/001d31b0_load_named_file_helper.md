# 0x001d31b0 load_named_file_helper

| field | value |
|---|---|
| Original address | 0x001d31b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d31b0 |
| Resolved name | load_named_file_helper |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d2e00, FUN_001d2f20, FUN_001d3020, FUN_001d30b0, FUN_001d30f0, FUN_001d41c0
**Callees:** FUN_00109ab0, FUN_00109eb8, FUN_001a4cd0, FUN_001cb360
**Referenced globals:** 0x24d1b0/0x24d1c8 path affixes; 0x3435bc scratch dest
**Referenced strings:** (path affixes @0x24d1b0/0x24d1c8)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic helper: builds a path string (prefix 0x24d1b0 + name + suffix 0x24d1c8), disc-loads it, and hands the buffer to FUN_001a4cd0.

## Notes / uncertainty
Shared helper (6 callers): prefix 0x24d1b0 + name + suffix 0x24d1c8, disc-read into scratch 0x3435bc, hand to FUN_001a4cd0 on success. FUN_001a4cd0 role inferred. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d31b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
