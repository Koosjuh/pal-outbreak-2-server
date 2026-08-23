# 0x00625190 screen_sm_text_entry

| field | value |
|---|---|
| Original address | 0x00625190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00625190 |
| Resolved name | screen_sm_text_entry |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e720, FUN_0061e730, FUN_0061e740, FUN_0061e750, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f0f0, FUN_0061f180, FUN_0061f1a0, FUN_0061f1b0, FUN_0061f220, FUN_0061f250, FUN_0061f270, FUN_0061f490, FUN_0061f4b0, FUN_0061f680, FUN_0061f760, FUN_006250e0, FUN_006345e0, FUN_00634ab0, FUN_006371d0
**Referenced globals:** 0x7152e1 substate; 0x7152e4 timer; 0x7152e8 cursor; 0x7152b0 name buf; 0x86f810 saved name; 0x3434a8/a0 params
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; sRam007152e4; uRam007152e8

## Behavioral explanation
Screen state machine for a name/keyboard entry screen: draws elements, reads input (e750 + f250e0 mask), commits the entered string (0x7152b0 <-> 0x86f810) via FUN_00634ab0/006345e0/00637180.

## Notes / uncertainty
Name-entry screen: confirm-current vs edit-via-soft-keyboard (FUN_006345e0/34ab0/37180); commits typed string 0x7152b0->0x86f810. Only caller of input_button_to_mask. Keyboard params (0x3434a8/a0) not fully decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00625190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
