# 0x005ec430 parse_attr_value_semicolon

| field | value |
|---|---|
| Original address | 0x005ec430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec430 |
| Resolved name | parse_attr_value_semicolon |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e9ef0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a ="..." attribute value terminating at '"' or ';' (style-list style), copying into a bounded buffer.

## Notes / uncertainty
Simplest variant: terminates on '"' or ';' (style-list value); plain byte copy, no tables. Single caller 0x5e9ef0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
