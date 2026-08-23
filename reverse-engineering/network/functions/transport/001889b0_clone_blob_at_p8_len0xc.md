# 0x001889b0 clone_blob_at_p8_len0xc

| field | value |
|---|---|
| Original address | 0x001889b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001889b0 |
| Resolved name | clone_blob_at_p8_len0xc |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1d90, FUN_001d1e40, FUN_001d2170, FUN_001d2290, FUN_001d26f0
**Callees:** FUN_00184170
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Deep-copies blob at *(param_1+8), len at blob+0xc, byte-granular; alloc class 4; returns alloc HANDLE (pre-resolution). Container/blob header layout undecoded. Sibling of 0x00188a30.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001889b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
