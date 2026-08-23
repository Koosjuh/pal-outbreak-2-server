# 0x005ca1a0 room_state_advance

| field | value |
|---|---|
| Original address | 0x005ca1a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca1a0 |
| Resolved name | room_state_advance |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cc980, FUN_005cce30, FUN_005d5b10, FUN_005d8840
**Referenced globals:** 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e

## Behavioral explanation
Dispatches on room sub-state (0x2e = 9/8/4/2/1): runs roster pass or net-result process and, on success, advances the screen via FUN_005d5b10.

## Notes / uncertainty
Room-screen per-frame dispatcher on kind 0x701070+0x2e: 8/9=list settle(5cce30), 4=roomlist req(5d8840)+advance, 1/2=net result(5cc980, adv on 1 or -1); advance via 5d5b10. Sub-processor bodies + kind meanings inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca1a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
