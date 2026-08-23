# 0x005ae260 session_seq_step2_load

| field | value |
|---|---|
| Original address | 0x005ae260 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae260 |
| Resolved name | session_seq_step2_load |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130
**Callees:** FUN_005af2f0, FUN_005c80a0, FUN_005de2a0
**Referenced globals:** 0x3435bc(base); 0x701f20; obj +0x993
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-seq step 2: kicks a data/resource load (FUN_005de2a0 at iRam003435bc+0x2ff000, FUN_005c80a0(1)), advances cursor.

## Notes / uncertainty
FUN_005ae130 case 2. Advances cursor first, then kicks async load: FUN_005de2a0(*(0x3435bc)+0x2ff000), FUN_005c80a0(1), FUN_005af2f0(0,10). Pairs with step3 poll. Loaded section/args inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae260.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
