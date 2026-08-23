# 0x001d0c90 load_npc_motion_table_if_allowed

| field | value |
|---|---|
| Original address | 0x001d0c90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0c90 |
| Resolved name | load_npc_motion_table_if_allowed |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360, FUN_001d09c0
**Referenced globals:** 0x259258 id allowlist; 0x502fa0 roster grid; uRam003435bc work base
**Referenced strings:** 0x24cd60 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If param_1&0xff is in allowlist DAT_00259258, builds tmpl 0x24cd60, sends and decodes a grid20 into 0x502fa0 via FUN_001d09c0.

## Notes / uncertainty
MISCLASSIFICATION CORRECTED. ELF 0x24cd60 = 'data\rom\motion\npc\rn%02d_tbl.bin'. Loads NPC motion table into 0x502fa0 only if id in -1-terminated allowlist DAT_00259258. Uncertainty: allowlist contents not dumped; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
