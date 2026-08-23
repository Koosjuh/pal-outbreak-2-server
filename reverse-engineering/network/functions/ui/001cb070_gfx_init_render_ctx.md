# 0x001cb070 gfx_init_render_ctx

| field | value |
|---|---|
| Original address | 0x001cb070 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb070 |
| Resolved name | gfx_init_render_ctx |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_0015c920
**Referenced globals:** 0x36b900=render ctx ptr; 0x36b920=render ctx; 0x259250=gfx template
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes a 0x98-byte render/display context at 0x36b920 and hands a small descriptor to the graphics library (FUN_0015c920).

## Notes / uncertainty
Zeroes 0x98-byte render ctx @0x36b920, builds 0x20-byte descriptor from DAT_00259250, registers via FUN_0015c920. Pure gfx setup; init half of the init/teardown pair. Descriptor flag semantics inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
