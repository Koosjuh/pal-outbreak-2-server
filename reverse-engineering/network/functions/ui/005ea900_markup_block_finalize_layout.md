# 0x005ea900 markup_block_finalize_layout

| field | value |
|---|---|
| Original address | 0x005ea900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea900 |
| Resolved name | markup_block_finalize_layout |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ea880, FUN_005f0e10
**Callees:** FUN_005ec100, FUN_005efa60, FUN_005efb30, FUN_005efc60
**Referenced globals:** +0xd894 (cell index); +0x18d (dirty); +0x186 (mode); +0x252f/+0x24e0 (cell layout struct); +0xe10
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd894; +0x186; +0x18d

## Behavioral explanation
Finalizes a block element: clears dirty +0x18d, computes per-cell layout at +0x24e0 base, runs FUN_005ec100/005efb30/005efc60 and optional FUN_005efa60 when not in table mode (+0x186==0).

## Notes / uncertainty
Shared cell finalize: clears dirty +0x18d, indexes cell struct (base +0x24e0, stride 0x5C, idx +0xd894), set-align from cell+0x252f (FUN_005ec100), layout passes A/B, extra non-table pass FUN_005efa60(+0xe10) when +0x186==0. void sig keys off globals; ignored caller args. Cell field layout beyond +0x252f/+0x24e0 unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
