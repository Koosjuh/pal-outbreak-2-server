# 0x00115e60 sif_rpc_bind_ready

| field | value |
|---|---|
| Original address | 0x00115e60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00115e60 |
| Resolved name | sif_rpc_bind_ready |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017f948, FUN_0017faa8, FUN_001ef2e0, FUN_001f27c8
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Pure predicate: node!=0 && client srv-id==node+0x18 && (node+0x10 & 1 DONE). Unambiguous; status-bit producer (SIF reply ISR) not traced.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00115e60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
