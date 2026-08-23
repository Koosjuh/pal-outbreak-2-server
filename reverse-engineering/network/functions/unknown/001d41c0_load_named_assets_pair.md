# 0x001d41c0 load_named_assets_pair

| field | value |
|---|---|
| Original address | 0x001d41c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d41c0 |
| Resolved name | load_named_assets_pair |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d31b0
**Referenced globals:** 0x24da58/0x24da60 paths
**Referenced strings:** (paths @0x24da58/0x24da60)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads two fixed-name assets (0x24da58 slot1, 0x24da60 slot0xc) via the generic loader 0x1d31b0.

## Notes / uncertainty
Loads two asset groups via FUN_001d31b0: (0x24da58,1) and (0x24da60,0xc). Not network. Group contents undecoded; second arg read as count.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d41c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
