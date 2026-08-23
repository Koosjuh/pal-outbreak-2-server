# 0x005eb5a0 markup_element_open_t3

| field | value |
|---|---|
| Original address | 0x005eb5a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb5a0 |
| Resolved name | markup_element_open_t3 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec100, FUN_005ef5e0, FUN_005ef850, FUN_005f0e10
**Referenced globals:** +4; +0xd894; +0x252f (cell flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd894

## Behavioral explanation
Type-3 element open: FUN_005f0e10(...,3), layout FUN_005ef5e0 + commit FUN_005ef850(3), sets per-cell flag +0x252f=1 and refreshes via FUN_005ec100.

## Notes / uncertainty
Open kind-3 (FUN_005ef5e0 prep), sets cell open flag +0x252f=1, FUN_005ec100 refresh. Tag mapping (table/pre?) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb5a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
