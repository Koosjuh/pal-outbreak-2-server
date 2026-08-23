# 0x00610830 room_create_menu_sm

| field | value |
|---|---|
| Original address | 0x00610830 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00610830 |
| Resolved name | room_create_menu_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_001b00e0, FUN_001b0100, FUN_001b0110, FUN_0060e1c0, FUN_0060e820, FUN_0060e9b0, FUN_0060ee80, FUN_0060ef20, FUN_0060f1b0, FUN_0060f2c0, FUN_00611fe0, FUN_00612020, FUN_006120a0, FUN_00614960, FUN_00614990, FUN_006149f0, FUN_00614ad0, FUN_006150b0, FUN_006153b0, FUN_00615430, FUN_00615470, FUN_00618210, FUN_00618230, FUN_00618460, FUN_00618510, FUN_006185f0, FUN_00618600, FUN_006186d0, FUN_006186e0
**Referenced globals:** ctx+0x20 (create sub-state); ctx+0x21 (return-state); ctx+0x10-0x1f (edit fields: players/scenario/region/pw); ctx+0x600/0x25c/0x268 (room record/slot); uRam003433b0 (input bits); ctx+0x4a-0x50 (layout selectors)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x20 create state; uRam003433b0 input; ctx+0x10 player-count; ctx+0x2e error latch

## Behavioral explanation
Large create-room configuration state machine (switch ctx+0x20, states 0-0x13): edits player-count/scenario/region/password/points fields from input bits, drives dialog nav (FUN_00618xxx), and in case 0x12 commits — resolves the room (FUN_0060e1c0/0060f1b0 reserved-check), opens query (FUN_0060ef20/0060ee80), claims slot (FUN_0060f2c0), registers+enters (FUN_0060e9b0/0060e820) and returns 1.

## Notes / uncertainty
Already fully reconstructed: 20-state create menu; case 0x12 COMMIT is the protocol carrier (scenario resolve, reserved/slot gate, claim ownership, op09 register + op06 enter, prime send, return 1). Field-editor cases 2-0x11 summarized not each expanded; occupied-slot test +0xb700/+0xc200/+0xc225 inferred. This case 0x12 is the client half of the create-registration blocker.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00610830.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
