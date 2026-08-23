# 0x005ffa90 room_subpage_enter_0x21

| field | value |
|---|---|
| Original address | 0x005ffa90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ffa90 |
| Resolved name | room_subpage_enter_0x21 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ff9f0
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005c2120
**Referenced globals:** iRam003435d4+0xc942c member/display region
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xf step; param_1+0x42b screen-id=0x21

## Behavioral explanation
Room sub-page enter stub: sets screen-id 0x21, zeroes a 0x20c0 display region, registers render cb 0x6014c0.

## Notes / uncertainty
Two-phase enter: first tick clears 0x20c0 panel, stamps pending_tag(0x6c4fbb)=0x21, registers render cb 0x6014c0; then holds. Confirmed blk==0x6c4b90 via +0x42b==pending_tag.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ffa90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
