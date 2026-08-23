# 0x005f4b80 softkbd_try_open

| field | value |
|---|---|
| Original address | 0x005f4b80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4b80 |
| Resolved name | softkbd_try_open |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7c80, FUN_005fec30, FUN_005fede0, FUN_00600200, FUN_0062d640
**Callees:** FUN_005b18c0
**Referenced globals:** cRam006c4ba3(kbd open flag); cRam006c50fb(kbd active); uRam006c4ba4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4ba3; cRam006c50fb

## Behavioral explanation
Attempts to open the on-screen keyboard (guarded), setting the active flags on success.

## Notes / uncertainty
Guarded OSK-session open: opens iff !cRam006c4ba3 && !cRam006c50fb && FUN_005b18c0()!=0, sets ba3=1/ba4=0. Precondition predicate of 005b18c0 (pad-edge vs focus) unproven. Gates the string that later feeds op04/op48. No wire here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4b80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
