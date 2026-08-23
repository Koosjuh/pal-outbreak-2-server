# 0x0061f600 input_icon_enqueue

| field | value |
|---|---|
| Original address | 0x0061f600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f600 |
| Resolved name | input_icon_enqueue |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00623800, FUN_00625670, FUN_00626e70
**Callees:** —
**Referenced globals:** 0x715330/0x715338 (queue B + type); 0x715313 (queue count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715313

## Behavioral explanation
Enqueues an icon/glyph id (1..0xf) into the render queue at 0x715330 with type 3, capped at 8 entries.

## Notes / uncertainty
Already reconstructed: icon ids 1..0xf -> list B style 3, cap 8, no default. Icon id->glyph mapping unrecovered. Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
