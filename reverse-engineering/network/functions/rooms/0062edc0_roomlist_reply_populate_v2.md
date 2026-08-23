# 0x0062edc0 roomlist_reply_populate_v2

| field | value |
|---|---|
| Original address | 0x0062edc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062edc0 |
| Resolved name | roomlist_reply_populate_v2 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005bff80, FUN_005c01d0, FUN_005c0210, FUN_005c0860, FUN_005c09c0, FUN_005c1c10
**Referenced globals:** 0x6c0760 room table; 0x6c4602 room count; 0x6c4b90 block; 0x6c5530 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb pending-step(==9); 0x6c4b9f substate

## Behavioral explanation
Room-list reply callback variant (cRam006c4fbb==9): like e9b0, unpacks room count 0x6c4602 and per-room fields (0x6c0762/76e/76f/774) into table 0x6c0760; sets b9f=1, timer 0x6c5530=0x708.

## Notes / uncertainty
Already fully reconstructed. Create-mode room-list refresh variant of 0062e9b0 with reduced field set + extra sub_step=0 reset. Open: which caller fires this vs primary; duplicated name re-read likely decompiler artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062edc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
