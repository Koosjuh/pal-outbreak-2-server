# 0x005b6030 clear_state_6c9d26_redraw

| field | value |
|---|---|
| Original address | 0x005b6030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6030 |
| Resolved name | clear_state_6c9d26_redraw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c9d26 (12-byte state block); 0x6c517c (redraw buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c9d26

## Behavioral explanation
Zero 12 bytes at 0x6c9d26, set uRam006c9d26=1, redraw dialog 0x6c517c.

## Notes / uncertainty
Unconditional: memset 12B block 0x6c9d26, set byte0=1 (default selection), redraw 0x6c517c. Sequence exact; block field layout inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
