# 0x005cd760 cursor_struct_init

| field | value |
|---|---|
| Original address | 0x005cd760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd760 |
| Resolved name | cursor_struct_init |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9460
**Callees:** —
**Referenced globals:** 0x701078 cursor struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701078

## Behavioral explanation
Initializes the cursor/selection struct at 0x701078 (mode=1, geometry 0x96/100, offsets cleared).

## Notes / uncertainty
Inits cursor struct 0x701078: mode=1, hold=0, target(0x10/0x12)=150/100, acc(0x14/0x18)=0. Byte-offset layout cross-confirmed vs scroll_view_to_entry; coordinate space inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
