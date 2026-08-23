# 0x005e9e70 markup_meta_block_reset

| field | value |
|---|---|
| Original address | 0x005e9e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9e70 |
| Resolved name | markup_meta_block_reset |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** func_0x00106b60(memset)
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x1120 (0x108 block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes the 0x108-byte state block at cfg+0x1120.

## Notes / uncertainty
memset(+0x1120,0,0x108): clears meta-tag block (matched flag/value/string) used by 0x9ea0/0x9ef0/0x9f40/0x9f80. Leaf.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9e70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
