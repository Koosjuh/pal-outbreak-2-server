# 0x005eaad0 markup_attr_parse_short_e02_celldefault

| field | value |
|---|---|
| Original address | 0x005eaad0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eaad0 |
| Resolved name | markup_attr_parse_short_e02_celldefault |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec6d0
**Referenced globals:** +0x186 (gate); +0xd894 (cell idx); +0x24e0 (cell struct); +0xe02 (attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode 0xf6): parses tag field with FUN_005ec6d0 using the current cell's field (+0x24e0->+0x1c) as default, stores at +0xe02.

## Notes / uncertainty
Renamed _default->_celldefault: u16 cell-attr into +0xe02 with default derived from current cell (cell ptr array +0x24e0[idx], field +0x1c, null-guarded), FUN_005ec6d0(token,default). Meaning of cell+0x1c default and parse grammar unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eaad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
