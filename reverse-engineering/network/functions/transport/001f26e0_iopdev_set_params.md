# 0x001f26e0 iopdev_set_params

| field | value |
|---|---|
| Original address | 0x001f26e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f26e0 |
| Resolved name | iopdev_set_params |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d4380
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Local-only: block[index] +0x18=param_a,+0x1c=param_b,+0x14=0; params must be >=0. NOTE: no index bounds check (unlike siblings) — latent OOB write flagged. Field meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f26e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
