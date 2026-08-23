# 0x005e7710 parse_context_reset

| field | value |
|---|---|
| Original address | 0x005e7710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e7710 |
| Resolved name | parse_context_reset |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7e30
**Callees:** FUN_005ec100, FUN_005ec4f0
**Referenced globals:** iRam007012a0 (parser context base; +0x186 mode, +0x191/+0x192 list state, +0x49 slot idx, +0x2a3/+0x2b3/+0x193/+0x1a3 sub-parser buffers)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186

## Behavioral explanation
Resets/initializes the lobby parser context (@0x7012a0): zeros ~30 state fields (mode, counters, list state) and seeds four sub-parser slots via FUN_005ec4f0, setting parse mode +0x186 from the arg.

## Notes / uncertainty
Reset/init of the lobby text/markup parser ctx @0x7012a0: zeroes ~30 state fields, strcpys 4 default tag strings (0x648220..38), builds 3 sub-parsers via FUN_005ec4f0, memsets a 0x108 record + 0x100 tail. Far list-state offsets kept as decompiler u32*-relative element indices; tag string text unresolved; state value 3 meaning unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e7710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
