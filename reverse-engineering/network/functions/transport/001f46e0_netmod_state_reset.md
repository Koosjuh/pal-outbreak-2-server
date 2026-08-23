# 0x001f46e0 netmod_state_reset

| field | value |
|---|---|
| Original address | 0x001f46e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f46e0 |
| Resolved name | netmod_state_reset |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0061d6a0, FUN_0061ded0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Straight-line reset of 0x390800 block: zero head/tail, set enabled(0x3908cc=1), invalidate handle(0x390824=0xffffffff), clear 0x390814. Field roles inferred from reset pattern; no caller/reader resolved.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f46e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
