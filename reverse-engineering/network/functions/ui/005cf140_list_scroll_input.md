# 0x005cf140 list_scroll_input

| field | value |
|---|---|
| Original address | 0x005cf140 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cf140 |
| Resolved name | list_scroll_input |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5ed0
**Referenced globals:** 0x701068+0x4f8a4 buttons; 0x715da8+0x49c keyboard
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Maps pad up/down (0x4f8a4 bits / keyboard) to list scroll steps FUN_005d5ed0(1)/FUN_005d5ed0(0).

## Notes / uncertainty
Thin scroll dispatcher: pad 0x10/'(' -> FUN_005d5ed0(1), pad 0x200/')' -> FUN_005d5ed0(0). Direction sign of arg 1/0 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cf140.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
