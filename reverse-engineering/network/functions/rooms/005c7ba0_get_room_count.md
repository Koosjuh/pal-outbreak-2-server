# 0x005c7ba0 get_room_count

| field | value |
|---|---|
| Original address | 0x005c7ba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7ba0 |
| Resolved name | get_room_count |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00606fc0
**Callees:** —
**Referenced globals:** 0x365e1e (room count); 0x6feba8 (mirror)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads the room/entry count (0x365e1e) into caller out-param and mirror 0x6feba8.

## Notes / uncertainty
Reads roomlist length 0x365e1e into out-param and mirror 0x6feba8; always returns 0. 0x365e1e as count inferred from position/adjacency to 0x365e20.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7ba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
