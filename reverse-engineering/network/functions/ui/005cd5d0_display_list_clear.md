# 0x005cd5d0 display_list_clear

| field | value |
|---|---|
| Original address | 0x005cd5d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd5d0 |
| Resolved name | display_list_clear |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dfee0
**Referenced globals:** 0x701068+0x5ffc0 display-list; 0x701070+2 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+2

## Behavioral explanation
Frees every populated entry in the 0x5ffc0[500] display list (FUN_005dfee0 per entry) then advances to step 3.

## Notes / uncertainty
Step-2: frees packed display list ov+0x5ffc0[<500] via FUN_005dfee0 until first null; scr+2=3. FUN_005dfee0 takes no arg yet must advance an internal cursor — mechanism unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd5d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
