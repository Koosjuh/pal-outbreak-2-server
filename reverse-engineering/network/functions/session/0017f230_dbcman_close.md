# 0x0017f230 dbcman_close

| field | value |
|---|---|
| Original address | 0x0017f230 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017f230 |
| Resolved name | dbcman_close |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017e700
**Callees:** FUN_00115c68, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sync RPC fn0x302 CLOSE: sends handle at +0x00, returns status at +0x04. Init-gated. Reply-word semantics unconfirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017f230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
