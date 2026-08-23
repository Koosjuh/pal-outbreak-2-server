# 0x005e00e0 texture_handle_get

| field | value |
|---|---|
| Original address | 0x005e00e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e00e0 |
| Resolved name | texture_handle_get |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daba0, FUN_005e0570, FUN_005e07c0, FUN_005e1670, FUN_005e2060, FUN_005e4b00, FUN_005e4f10, FUN_005e5200, FUN_005e5650
**Callees:** —
**Referenced globals:** iRam00701068+0x607c0 (texture handle table); iRam00701068+0x609c0 (texture count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bounds-checked lookup of a texture/sprite-sheet handle from the table @+0x607c0 by index; returns -1 if out of range.

## Notes / uncertainty
Bounds-checked signed-char index lookup into texture table@+0x607c0 (count byte@+0x609c0); returns 0xFFFFFFFF sentinel if <0 or >=count. Handle representation (VRAM id vs ptr) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e00e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
