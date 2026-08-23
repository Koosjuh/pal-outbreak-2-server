# 0x001bf5e0 net_adaptor_init

| field | value |
|---|---|
| Original address | 0x001bf5e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001bf5e0 |
| Resolved name | net_adaptor_init |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0011a660, FUN_001bf380, FUN_001bf530, FUN_001bf5c0, FUN_001c0230
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Ethernet adaptor bring-up: clear driver state (FUN_001c0230), register 6 ifdescs via FUN_001bf380 modes{1,0,1,9,0}, probe device 0x248400, populate desc 0x35c3b8 (type 0x21) + publish uRam0035c3d8. Register-fn/mode semantics inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001bf5e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
