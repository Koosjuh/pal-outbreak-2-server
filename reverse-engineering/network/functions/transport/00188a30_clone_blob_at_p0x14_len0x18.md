# 0x00188a30 clone_blob_at_p0x14_len0x18

| field | value |
|---|---|
| Original address | 0x00188a30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00188a30 |
| Resolved name | clone_blob_at_p0x14_len0x18 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d0510, FUN_001d06d0
**Callees:** FUN_00184170
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Deep-copies blob at *(param_1+0x14), len at blob+0x18, WORD-granular (len>>2); alloc class 4; returns handle. Non-mult-of-4 len would truncate (implies invariant). Sibling of 0x001889b0 (two sub-records per container?).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00188a30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
