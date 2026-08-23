# 0x006130a0 room_member_slots_render

| field | value |
|---|---|
| Original address | 0x006130a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006130a0 |
| Resolved name | room_member_slots_render |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_0060e1c0, FUN_0060f8b0, FUN_006146e0, FUN_00614720, FUN_00614870
**Referenced globals:** ctx+600 (member slot records, 0x14 stride); ctx+0x25c (slot-valid); ctx+0xaf00 (per-slot net record 0x1340); fmt 0x6540e8/0x6540f0; ctx+0x14/0x1e (cursor/scroll)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+600 slot table; ctx+0x24 room-member count

## Behavioral explanation
Renders the room member/player list: for up to 2 visible slots (+0x1e scroll base) reads slot state from ctx+600 table (+0x25c valid, +600 state 1/2), colors occupied/empty, resolves the player name (FUN_0060e1c0) or a default (ctx tbl+0x28), and draws '#N name'; also renders the highlighted current slot.

## Notes / uncertainty
Renders 2 visible '#N name' member rows + highlighted current slot from ctx iRam0070d1c0 (slot stride 0x14, net stride 0x1340); dim color on invalid/state2/pending, default name on unresolved. Likely a distinct compact room view (separate ctx from 0x70b410/0x6970a0 panels); slot state codes and net pending-triple inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006130a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
