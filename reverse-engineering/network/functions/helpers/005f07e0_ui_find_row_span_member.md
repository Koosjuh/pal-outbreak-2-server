# 0x005f07e0 ui_find_row_span_member

| field | value |
|---|---|
| Original address | 0x005f07e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f07e0 |
| Resolved name | ui_find_row_span_member |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f0a10
**Callees:** —
**Referenced globals:** +0x186 render-pass; +0x24e0 node pool; node+0x4c key, +0x48 span, +0x36 chain
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Finds a sibling node matching a row/col key (+0x4c vs param[0x13]) with rowspan>1; two lookup paths for draw-mode linked list vs measure-mode index chain.

## Notes / uncertainty
Two-path row-span partner lookup: build searches sibling list by key +0x4c (span>1), else direct pool[+0x36]. +0x4d 'instantiated' guard inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f07e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
