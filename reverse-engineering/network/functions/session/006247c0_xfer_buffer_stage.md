# 0x006247c0 xfer_buffer_stage

| field | value |
|---|---|
| Original address | 0x006247c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006247c0 |
| Resolved name | xfer_buffer_stage |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00623be0
**Callees:** —
**Referenced globals:** 0x715298 struct ptr; 0x3c8a90 stage buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stages a 0x1d7c-byte transfer record from struct+0x170 into fixed buffer 0x3c8a90 and registers it via func_0x001f3580.

## Notes / uncertainty
Send-side: memcpy(struct+0x170 stage buf <- global 0x3c8a90, 0x1d7c) then submit 001f3580. Fixed 0x1d7c-byte record. Direction inferred from memcpy arg order + submit; wire framing unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006247c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
