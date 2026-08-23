# 0x005ddb40 gs_draw_sprite

| field | value |
|---|---|
| Original address | 0x005ddb40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ddb40 |
| Resolved name | gs_draw_sprite |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daba0, FUN_005e0570, FUN_005e07c0, FUN_005e15e0, FUN_005e1670, FUN_005e2060, FUN_005e4b00, FUN_005e4f10, FUN_005e5200, FUN_005e5650, FUN_005e5910
**Callees:** FUN_005dde10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets GS texture/blend registers (func_0x001a75e0, mode 0x63) and packs a sprite quad (8 shorts + color) forwarded to FUN_005dde10.

## Notes / uncertainty
Already fully reconstructed; verified. GS register semantics of func_0x0018c8d0 writes and tex_ref vs tex_id roles inferred, not runtime-proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ddb40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
