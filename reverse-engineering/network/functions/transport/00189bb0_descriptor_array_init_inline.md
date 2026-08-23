# 0x00189bb0 descriptor_array_init_inline

| field | value |
|---|---|
| Original address | 0x00189bb0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00189bb0 |
| Resolved name | descriptor_array_init_inline |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1e40, FUN_001d2170, FUN_001d2290, FUN_001d26f0
**Callees:** FUN_00186320, FUN_00189cf0, FUN_0018a0b0, FUN_0018a400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Inits contiguous array of n (=hdr.count16) 0x190-byte descriptors: +0xc2=n, +0x180/+0x182=0xffff sentinels, zeroed state words, +0x40 subobj, then bind/link/finalise. Descriptor domain identity (slot/index?) inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00189bb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
