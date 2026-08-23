# 0x001ee110 netstate_reset

| field | value |
|---|---|
| Original address | 0x001ee110 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee110 |
| Resolved name | netstate_reset |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ef310
**Referenced globals:** 0x0037a278 net-state; 0x0037a280 net-state; 0x0037a288 phase; 0x0037a290 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x0037a288 phase; 0x0037a290

## Behavioral explanation
Zeroes global net-state block (0x37a278/280/288/290) and calls FUN_001ef310 — reset the network/link subsystem state.

## Notes / uncertainty
Zeroes netlink state block (0x37a278/280/288/290, phase=0) + link_reset(1ef310). Byte-field 278/280 semantics undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
