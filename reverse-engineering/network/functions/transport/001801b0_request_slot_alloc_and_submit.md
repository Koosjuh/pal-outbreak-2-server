# 0x001801b0 request_slot_alloc_and_submit

| field | value |
|---|---|
| Original address | 0x001801b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001801b0 |
| Resolved name | request_slot_alloc_and_submit |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1960
**Callees:** FUN_00180340, FUN_001829c0, FUN_001840a0, FUN_001840d0, FUN_00184170
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Allocates slot in 640x0x180 request table iRam0027e5a8, serialises 0x24 header + two 16B-aligned payloads into alloc'd buffer, tags seq uRam0028a3f0, submits via FUN_00180340; bit2 of type=NO_BUFFER. Latent overflow if all 640 slots busy (scan cap lacks guard). Descriptor/slot field names inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001801b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
