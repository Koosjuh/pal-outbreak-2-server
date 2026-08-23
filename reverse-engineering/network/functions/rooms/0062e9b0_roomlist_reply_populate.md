# 0x0062e9b0 roomlist_reply_populate

| field | value |
|---|---|
| Original address | 0x0062e9b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e9b0 |
| Resolved name | roomlist_reply_populate |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005bff80, FUN_005c01d0, FUN_005c0210, FUN_005c0260, FUN_005c0370, FUN_005c0860, FUN_005c09c0, FUN_005c1c10
**Referenced globals:** 0x6c0760 room table; 0x6c4602 room count; 0x6c0764..0x6c0778 per-room fields; 0x6c4b90 block
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb pending-step(==9); 0x6c4b9f substate

## Behavioral explanation
Room-list reply callback (expects cRam006c4fbb==9): on status 0 reads room count into 0x6c4602 then per-room (stride 0x15c into 0x6c0760) unpacks id/state/attrs/name via FUN_005c02xx/03xx accessors; sets phase substate b9f=1.

## Notes / uncertainty
Already fully reconstructed. op49 room-list reply cb (pending_tag 9); status 0x00 full repopulate of 0x6c0760 (stride 0x15c), 0x02 incremental, else error. Open: individual accessor semantics inferred structurally.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e9b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
