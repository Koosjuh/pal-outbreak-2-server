# 0x0062cc60 room_action_confirm_cb_1e

| field | value |
|---|---|
| Original address | 0x0062cc60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cc60 |
| Resolved name | room_action_confirm_cb_1e |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005c4330, FUN_005c4370
**Referenced globals:** 0x6c4fbb trigger; 0x6c5c44 mode; 0x6c5c48.. sel ids; 0x6c517c marquee buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c4b90

## Behavioral explanation
Dialog callback for trigger 0x1e: on confirm sets uRam006c5c44=2 and commits selection via FUN_005c4330/5c4370; else marquee.

## Notes / uncertainty
Sibling of 0x1f for tag 0x1e; confirm commits a richer 5-field selection via FUN_005c4330(4 ids)+FUN_005c4370(extra) instead of inline copy. Commit-helper effects out of batch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cc60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
