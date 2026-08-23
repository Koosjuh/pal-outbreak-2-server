# 0x001d0c00 load_player_slot_motion

| field | value |
|---|---|
| Original address | 0x001d0c00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0c00 |
| Resolved name | load_player_slot_motion |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360, FUN_001d09c0
**Referenced globals:** 0x516870 per-room roster grid; uRam003435bc work base
**Referenced strings:** 0x24cd30 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Per-index (param_1) guarded by byte@(idx*0x1f48+0x516871): builds tmpl 0x24cd30, sends (flags 0x20001), decodes into grid20 at idx*0x1f48+0x516870 via FUN_001d09c0.

## Notes / uncertainty
MISCLASSIFICATION CORRECTED: motion loader, not roster. ELF 0x24cd30 = 'pl%02d_pc_000.bin'. Idempotent per-slot load guarded by byte at idx*0x1f48+0x516871; decodes into slot grid 0x516870+idx*0x1f48. Uncertainty: slot count/bound caller-guaranteed; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0c00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
