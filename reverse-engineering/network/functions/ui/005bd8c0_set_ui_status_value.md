# 0x005bd8c0 set_ui_status_value

| field | value |
|---|---|
| Original address | 0x005bd8c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd8c0 |
| Resolved name | set_ui_status_value |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdef0, FUN_005bdfe0
**Referenced globals:** 0x6cbc84/0x6cbc80/0x6cbc7e/0x6cbc7c (UI status fields)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI status setter: maps a result byte (0->0, '\''->0xff) into status field 0x6cbc84, stores a 16-bit value from payload+0xc into 0x6cbc80, sets field type 2 and a computed field (FUN_005bdef0), then pushes a UI refresh (FUN_005bdfe0(0)).

## Notes / uncertainty
Populates UI status block 0x6cbc7c..84 from a reply record; result byte 0x27 -> flag 0xFF, 0 -> 0. Meaning of value at rec+0xc and whether 0x27 is the op27 code are inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd8c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
