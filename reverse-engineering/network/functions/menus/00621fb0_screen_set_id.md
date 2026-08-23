# 0x00621fb0 screen_set_id

| field | value |
|---|---|
| Original address | 0x00621fb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00621fb0 |
| Resolved name | screen_set_id |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** —
**Referenced globals:** 0x715298 screen struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** puRam00715298

## Behavioral explanation
Screen-transition primitive: writes the new screen-id byte at struct+0 and clears the two substate bytes (+1,+2).

## Notes / uncertainty
Screen transition primitive: obj[0]=new id, obj[1]=obj[2]=0. Confirms +1 substate used by struct-family handlers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00621fb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
