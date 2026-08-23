# 0x001aa580 zero_init_block_0x640

| field | value |
|---|---|
| Original address | 0x001aa580 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001aa580 |
| Resolved name | zero_init_block_0x640 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce4b0
**Callees:** FUN_001aa510
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Wrapper: memset(param_1,0,0x640) via FUN_001aa510. Identity of the 1600-byte block unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001aa580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
