# 0x00612d10 screen_content_render_dispatch_0x4d

| field | value |
|---|---|
| Original address | 0x00612d10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00612d10 |
| Resolved name | screen_content_render_dispatch_0x4d |
| Subsystem | ui |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_0060e1c0, FUN_00612fd0, FUN_006130a0, FUN_00613380, FUN_006134b0, FUN_00613530, FUN_00613600, FUN_00613740, FUN_00613840, FUN_006139c0, FUN_00613aa0
**Referenced globals:** ctx+0x4d (content id); ctx+0x1e/0x24 (cursor/room-count); ctx+0x1180 (net ctx for names)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4d content selector

## Behavioral explanation
Content render dispatcher: switch(ctx+0x4d content id) routes to the specific panel renderer (room-member slots, room list, region select, room name/pw, scenario list, player entries, etc.) plus the common FUN_00612fd0 table pass.

## Notes / uncertainty
Rewrote from classified stub to full reconstruction. Content render dispatch on ctx+0x4d; cases 0x10/0x11/0x12 draw the 3-row roster window over member array at ctx+0xaf00 (stride 0x1340, scroll +0x1e, count +0x24) via FUN_0060e1c0/FUN_006139c0 -- the create-room roster panel. Stride/base should be cross-checked vs member_record.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00612d10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
