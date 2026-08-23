# 0x00608c80 inflate_blocks

| field | value |
|---|---|
| Original address | 0x00608c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608c80 |
| Resolved name | inflate_blocks |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060ae40
**Callees:** FUN_00609be0, FUN_00609c60, FUN_0060a650, FUN_0060b930, FUN_0060ba40, FUN_0060bc60, FUN_0060bca0
**Referenced globals:** 0x00693250 code-length-order; 0x0064b530 bit-mask-table
**Referenced strings:** invalid block type; too many length or distance symbols; invalid stored block lengths
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflate_blocks: the block-level DEFLATE state machine (stored/fixed/dynamic block parsing, Huffman table build), dispatching to inflate_codes and error-exiting via FUN_0060bca0.

## Notes / uncertainty
zlib block state machine (10 modes TYPE..BAD). blens alloc 258+nlen+ndist is the zlib-1.1.4 tell. Duplicated inline flush epilogues reproduced via macro shorthand; tree-builder callees named by role. No runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
