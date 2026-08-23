# 0x001841d0 netstack_teardown_stage2

| field | value |
|---|---|
| Original address | 0x001841d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001841d0 |
| Resolved name | netstack_teardown_stage2 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001a0eb0, FUN_001a1750, FUN_001ce970, FUN_001d13d0, FUN_001d1500, FUN_001d1610, FUN_001d4170
**Callees:** FUN_00182520, FUN_00183be0, FUN_00197af0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sets run-state uRam0027e580=2 then cascades three teardowns (FUN_00183be0/00197af0/00182520). Individual teardown roles and full state enum undecoded.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001841d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
