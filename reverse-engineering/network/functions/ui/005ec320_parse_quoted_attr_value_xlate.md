# 0x005ec320 parse_quoted_attr_value_xlate

| field | value |
|---|---|
| Original address | 0x005ec320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec320 |
| Resolved name | parse_quoted_attr_value_xlate |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e93f0, FUN_005e9ea0
**Callees:** —
**Referenced globals:** DAT_006491b0 (char class); DAT_006493b0 (xlate table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Like parse_quoted_attr_value but maps each copied byte through translation table 0x6493b0 (case/charset fold); stops on " or class-4 char.

## Notes / uncertainty
Fold variant of 0x5ec1b0: single-byte, maps each byte through DAT_006493b0 (case/charset fold, shared with color parser). No multibyte path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
