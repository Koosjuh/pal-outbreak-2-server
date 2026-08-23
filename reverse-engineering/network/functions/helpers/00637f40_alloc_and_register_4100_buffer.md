# 0x00637f40 alloc_and_register_4100_buffer

| field | value |
|---|---|
| Original address | 0x00637f40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637f40 |
| Resolved name | alloc_and_register_4100_buffer |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00636890
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a 0x4100-byte buffer (func_0x001cbcb0) and registers it via two runtime calls if non-null.

## Notes / uncertainty
Allocates 0x4100 buffer, null-guards, registers via two callbacks (slots 1 and 4). Register callees + buffer purpose (texture/DMA/scratch) inferred, not opened.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
