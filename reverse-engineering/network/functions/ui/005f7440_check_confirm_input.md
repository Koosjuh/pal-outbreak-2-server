# 0x005f7440 check_confirm_input

| field | value |
|---|---|
| Original address | 0x005f7440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7440 |
| Resolved name | check_confirm_input |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f7270
**Callees:** —
**Referenced globals:** 0x6c4fba (button edge latch); 0x6c4ba6 (pad state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fba

## Behavioral explanation
Reads a pad/edge state (func_0x001c2770 over 0x6c4fba/0x6c4ba6); returns true and clears 0x6c4fba when the confirm button fired.

## Notes / uncertainty
One-shot confirm-edge test over latch 0x6c4fba / pad 0x6c4ba6; consumes latch on fire. Which physical button not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
