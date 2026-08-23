# 0x001c4450 recv_session_params_block

| field | value |
|---|---|
| Original address | 0x001c4450 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4450 |
| Resolved name | recv_session_params_block |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0
**Referenced globals:** 0x368484..0x368492 param block; conn+0x30 peer; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0xd next-state=0x04

## Behavioral explanation
Reply handler that loads an 8-field parameter block (timeouts/limits) into 0x368484..0x368492 — literal defaults on peer-gone, else 8 u16 reads; advances to state 0x04.

## Notes / uncertainty
Rewrote: loads 8x big-endian u16 timing/limit block 0x368484..0x368492 (defaults 0x14/0x12c/0x12c/0x1518/0x708x4 on empty reply), ->state 0x04. Per-field timing roles inferred from magnitude.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4450.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
