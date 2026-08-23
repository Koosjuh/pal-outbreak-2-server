# 0x005d1d60 input_activate_gate

| field | value |
|---|---|
| Original address | 0x005d1d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d1d60 |
| Resolved name | input_activate_gate |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d1e80
**Callees:** —
**Referenced globals:** 0x715da8+0x49c/0x49d pad keys; 0x701068+0x4f8a0/0x4f8a4 input flags; 0x701068+0x4f8a8 stick active
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x4f8a0; 0x701068+0x4f8a4

## Behavioral explanation
Returns +1/-1 gate telling the activate dispatcher whether the current pad/key + input-flag state permits a click this frame.

## Notes / uncertainty
Predicate: returns +1(allow click) only on clean frame (no dir key 0x4f-0x52/0x28, no pad-flag dir bits, stick idle) else -1. Caller 1e80 tests sign. 0x28 key identity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d1d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
