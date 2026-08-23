# 0x00606cf0 roomlist_screen_tick

| field | value |
|---|---|
| Original address | 0x00606cf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606cf0 |
| Resolved name | roomlist_screen_tick |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_00606fc0, FUN_00607260, FUN_00607340, FUN_00607370, FUN_006075e0, FUN_006076c0, FUN_00618c30
**Referenced globals:** 0x0070cdb8 screen-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070cdb8

## Behavioral explanation
Per-frame state-machine dispatcher: switch(0070cdb8) states 0-5 into the room-query/select screen handlers, then render tick FUN_00618c30.

## Notes / uncertainty
Top-level room-list/query-select tick: switch(uRam0070cdb8 0..5) into 606fc0/607260/607340/607370/6075e0/6076c0 then render 00618c30. Outer driver above the detail SMs; drives op1c/op20/op49 list flow (sub-handlers touch 0x8744f8/0x3c8a80/socket). Per-state labels inferred from callee globals, not from reading sub-handlers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606cf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
