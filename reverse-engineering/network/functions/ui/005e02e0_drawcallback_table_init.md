# 0x005e02e0 drawcallback_table_init

| field | value |
|---|---|
| Original address | 0x005e02e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e02e0 |
| Resolved name | drawcallback_table_init |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c80a0, FUN_005c8870
**Callees:** —
**Referenced globals:** 0x7010a0 (draw-callback fn-ptr table); uRam00701098 (count); uRam00701090
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00701098

## Behavioral explanation
Clears the per-frame draw-callback table (128 slots @0x7010a0) and its count/aux (uRam00701098/0x90).

## Notes / uncertainty
Clears the 128-slot per-frame draw-callback table @0x7010a0 and counts 0x701098/0x701090. Role of aux word 0x701090 (cleared here, untouched by register/dispatch) unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e02e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
