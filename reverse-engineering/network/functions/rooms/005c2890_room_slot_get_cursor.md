# 0x005c2890 room_slot_get_cursor

| field | value |
|---|---|
| Original address | 0x005c2890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2890 |
| Resolved name | room_slot_get_cursor |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5f60, FUN_00601060, FUN_0062eff0
**Callees:** —
**Referenced globals:** 0x6cfa2c/0x6cfa2e (per room-slot cursor pos, stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads room-slot param_1's two cursor/position shorts (0x144-stride) into out-params; no-op if slot==0.

## Notes / uncertainty
Getter mirror of FUN_005c2820: reads rec+0x2c/+0x2e cursor shorts; no-op if index==0 (1-based hint).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
