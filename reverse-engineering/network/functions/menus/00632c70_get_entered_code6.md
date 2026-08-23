# 0x00632c70 get_entered_code6

| field | value |
|---|---|
| Original address | 0x00632c70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00632c70 |
| Resolved name | get_entered_code6 |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2460
**Callees:** —
**Referenced globals:** 0x715da8+0x49c (entered chars)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x49c

## Behavioral explanation
Copies 6 bytes from the name-entry buffer (state+0x49c) into caller — reads out the entered short code/name characters.

## Notes / uncertainty
Copies 6 bytes +0x49c..+0x4a1 (entered short code) to caller. Semantic role of the 6-byte code depends on caller FUN_005b2460, not inspected.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00632c70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
