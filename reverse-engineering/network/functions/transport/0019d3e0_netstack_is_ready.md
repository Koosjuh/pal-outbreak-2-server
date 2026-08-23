# 0x0019d3e0 netstack_is_ready

| field | value |
|---|---|
| Original address | 0x0019d3e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0019d3e0 |
| Resolved name | netstack_is_ready |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0017e550, FUN_0017ee60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Two-stage readiness gate: true iff FUN_0017ee60()==1 && FUN_0017e550(0)==1 (short-circuit). Which subsystems (link/DHCP/IOP) report is unconfirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0019d3e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
