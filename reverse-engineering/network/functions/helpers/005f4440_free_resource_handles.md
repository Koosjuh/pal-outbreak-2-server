# 0x005f4440 free_resource_handles

| field | value |
|---|---|
| Original address | 0x005f4440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4440 |
| Resolved name | free_resource_handles |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_005f4480, FUN_005f4550, FUN_006233e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Releases the 0x4000-range (9) and 0x4100 asset handles and flushes.

## Notes / uncertainty
Frees handle range 0x4000x9 + 0x4100x1 then render/DMA flush; the (0x4000,9) count cross-checks load_resource_set. Counterpart of the loader. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
