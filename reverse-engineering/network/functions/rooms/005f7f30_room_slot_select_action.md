# 0x005f7f30 room_slot_select_action

| field | value |
|---|---|
| Original address | 0x005f7f30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7f30 |
| Resolved name | room_slot_select_action |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7800
**Callees:** FUN_005add90, FUN_005f5ea0, FUN_00627760, FUN_00627d40, FUN_0062d4e0
**Referenced globals:** 0x6c45fe (member count); 0x70b410 (slot table); param+0x907 (selected slot); param+0x53a
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x907

## Behavioral explanation
On confirm over slot +0x907: if it maps to a present member, latches the player id (from 0x70b410) into +6 and opens FUN_0062d4e0; otherwise dispatches the trailing menu options (add/kick/etc.) by index offset.

## Notes / uncertainty
Roster confirm: row 0->jump leave page(+0xe=4); row<min(count,6)=member->latch id from 0x70b410 into +6, open member screen 0062d4e0; row>=count->trailing option by idx (3/2/1/0). count=min(0x6c45fe,6). Trailing-option identities and row-0 semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7f30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
