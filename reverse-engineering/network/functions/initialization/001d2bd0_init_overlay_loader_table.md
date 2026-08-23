# 0x001d2bd0 init_overlay_loader_table

| field | value |
|---|---|
| Original address | 0x001d2bd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2bd0 |
| Resolved name | init_overlay_loader_table |
| Subsystem | initialization |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001840d0, FUN_001d2b30
**Referenced globals:** 0x3435d0 buffer base; 0x24d050 loader descriptor table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes a 0x300000 buffer, loads the overlay index, relocates offsets, then drives the PTR_FUN_0024d050 loader descriptor table via function pointers.

## Notes / uncertainty
Boot bootstrap: zero 0x300000 buf, load index, relocate 32 base-relative offsets, then interpret PTR_0024d050 {fn,src,dst,argc} descriptors (terminator 0x3e7, NA 0x63, arg-count 0/1/2/0x63 dispatch). Descriptor field semantics inferred. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2bd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
