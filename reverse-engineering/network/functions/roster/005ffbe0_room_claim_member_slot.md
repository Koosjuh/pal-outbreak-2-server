# 0x005ffbe0 room_claim_member_slot

| field | value |
|---|---|
| Original address | 0x005ffbe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ffbe0 |
| Resolved name | room_claim_member_slot |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ff9f0
**Callees:** FUN_005af2f0, FUN_006020e0
**Referenced globals:** iRam003435d4+0xc942c member-slot table; +0xcb4ec current-slot copy; +0xcf5c0 stats; 0x70b468 counter
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x908 own slot; param_1+0x44c active slot; param_1+0x4a2/0x15 slot mirror

## Behavioral explanation
On room entry, scans the 4 member slots (0x830 stride at 0xc942c) matching local id (func_0x00109d70 vs +0x1e3c) to find/claim own slot 0x908, initializes that member record ([0]=4,[1]=4,[3]=1) and copies name/id fields, then builds the room menu (FUN_006020e0).

## Notes / uncertainty
Seats local player into member-slot table (0xc942c stride 0x830): scans 4 candidates by id vs +0x1e3c, claims match (else fallback slot 0), state=4/self. Fallback reachability (whether candidates are always pre-populated by enter reply) is the open create-room question.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ffbe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
