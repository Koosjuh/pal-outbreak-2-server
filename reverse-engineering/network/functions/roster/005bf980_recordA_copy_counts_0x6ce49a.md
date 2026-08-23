# 0x005bf980 recordA_copy_counts_0x6ce49a

| field | value |
|---|---|
| Original address | 0x005bf980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf980 |
| Resolved name | recordA_copy_counts_0x6ce49a |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b0950
**Callees:** —
**Referenced globals:** 0x6ce49a registry-A render struct (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies param_2 16-bit words from registry-A render struct (idx*0x144+0x6ce49a) into caller buffer (name/array field).

## Notes / uncertainty
Bulk u16 copy from 0x144-stride record-A +0x00; caller clamps 2 words to 9999 (decimal counters). Field domain (cur/max vs score) not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
