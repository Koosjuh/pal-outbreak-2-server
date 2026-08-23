# 0x00635c60 kbd_enter_submenu_if_type12

| field | value |
|---|---|
| Original address | 0x00635c60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635c60 |
| Resolved name | kbd_enter_submenu_if_type12 |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634ab0
**Callees:** FUN_006375d0
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1f key-type; 0x248 status

## Behavioral explanation
If current key-type 0x1f is 1 or 2, descend via FUN_006375d0 (navigate/switch page); otherwise reject (status 0x248=5).

## Notes / uncertainty
If key-type +0x1f in {1,2} call page-switch FUN_006375d0, else reject status 5. Meaning of type 1 vs 2 not distinguished.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635c60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
