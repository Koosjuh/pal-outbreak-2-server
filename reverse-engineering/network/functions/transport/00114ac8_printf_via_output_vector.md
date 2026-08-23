# 0x00114ac8 printf_via_output_vector

| field | value |
|---|---|
| Original address | 0x00114ac8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00114ac8 |
| Resolved name | printf_via_output_vector |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0017e5f8, FUN_0017ee60, FUN_001e2424, FUN_001e3100, FUN_001e3a3c, FUN_001e4728, FUN_001f1fe0, FUN_001f22a0, FUN_001f2348, FUN_001f25e0
**Callees:** FUN_001141b0, FUN_00114498
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Variadic formatted-output shim: installs FUN_001141b0 as output sink via PTR_FUN_002098c4, stages 7 varargs into a stack vector, calls formatter FUN_00114498, restores sink. Semantics of formatter/sink not decoded; param_1 typed as fmt-string by convention.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00114ac8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
