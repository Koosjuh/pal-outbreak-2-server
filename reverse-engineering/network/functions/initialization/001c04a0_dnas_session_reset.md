# 0x001c04a0 dnas_session_reset

| field | value |
|---|---|
| Original address | 0x001c04a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c04a0 |
| Resolved name | dnas_session_reset |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0100
**Callees:** FUN_00106b60
**Referenced globals:** 0x35a720 scratch; 0x35a6d0 ctx; 0x35a6f4 =-1
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35a6f4

## Behavioral explanation
Zeroes per-attempt DNAS buffers (0x35a720 4KB scratch, 0x35a6d0/0x35a6f0 ctx) and sets 0x35a6f4=-1 before an auth attempt.

## Notes / uncertainty
Per-attempt reset at step state 0: zeros 4KB scratch 0x35a720 + ctx blocks, arms 0x35a6f4=0xffffffff. Distinct from cold-start module init.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c04a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
