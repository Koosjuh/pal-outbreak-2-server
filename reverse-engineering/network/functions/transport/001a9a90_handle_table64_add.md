# 0x001a9a90 handle_table64_add

| field | value |
|---|---|
| Original address | 0x001a9a90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a9a90 |
| Resolved name | handle_table64_add |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d1d90, FUN_001d1e40, FUN_001d2170, FUN_001d2290, FUN_001d26f0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
First-fit insert into 64-entry table 0x5a9060 (-1=empty); pairs with FUN_001a9ae0 remove. Handle meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a9a90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
