# 0x00635f80 kbd_nav_skip_disabled_keys

| field | value |
|---|---|
| Original address | 0x00635f80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635f80 |
| Resolved name | kbd_nav_skip_disabled_keys |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634ab0
**Callees:** FUN_006322c0, FUN_00633470, FUN_00634970, FUN_00637140, FUN_00637260, FUN_00637540, FUN_00637690, FUN_006378b0
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x2f mode; 0x1e active-key; 0x1f key-type; 0x48; 0x35 flags; 0x4a bit0; 0x36; 0x248 status

## Behavioral explanation
Directional key traversal that skips disabled keys: probes up to 4 neighbors via FUN_00637260 given the disabled bitmask, updates key 0x1e/type 0x1f, then repaints.

## Notes / uncertainty
Directional nav over 4-pos ring skipping disabled keys via probe FUN_00637260; param_1=direction. Busy-guard +0x2f; restore on no-move. Ring semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635f80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
