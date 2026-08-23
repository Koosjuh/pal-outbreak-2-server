# 0x0061f9f0 screen_sm_connect_a

| field | value |
|---|---|
| Original address | 0x0061f9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f9f0 |
| Resolved name | screen_sm_connect_a |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e720, FUN_0061e750, FUN_0061e7f0, FUN_0061e800, FUN_0061e940, FUN_0061ea20, FUN_0061f0d0, FUN_0061f0f0, FUN_0061f1b0, FUN_0061f250, FUN_0061f270, FUN_0061f4b0, FUN_0061f680, FUN_0061f8c0, FUN_0061f970, FUN_0061f9d0
**Referenced globals:** 0x7152e1 substate; 0x7152e4 timer; 0x7152e8 cursor; 0x3c98a0 role/link flag; 0x3c9580 link flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; sRam007152e4; sRam007152e8

## Behavioral explanation
Per-screen state machine (substate cRam007152e1) driving a connect/handshake screen: polls input direction (e750), cursor moves (e720), confirm/cancel (e7f0/e800), toggles windows.

## Notes / uncertainty
Global-SM connect/link-option select; returns selection+1 on confirm, starts net via func_0x001a6910(0,0,10). Callee UI/window semantics inferred, no runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
