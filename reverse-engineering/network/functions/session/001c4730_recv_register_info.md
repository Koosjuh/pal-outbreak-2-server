# 0x001c4730 recv_register_info

| field | value |
|---|---|
| Original address | 0x001c4730 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4730 |
| Resolved name | recv_register_info |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001c3b10
**Referenced globals:** 0x248338; 0x248358; 0x349f70 user-info; conn+0x30 peer; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0xd next-state=0x1f

## Behavioral explanation
Reply parser for state 0/7: reads several u32 fields into user/registration globals (0x248338,0x248358,0x349f70) plus 14 more discarded reads; advances to state 0x1f. On peer-gone tears down.

## Notes / uncertainty
Rewrote: post-login account parser (fsm-state 0/7): 3 u32 committed-if-nonzero to 0x248338/0x248358/0x349f70 + 14 reserved u32 discarded, ->state 0x1f; empty reply->conn_reset(code 9). Account-field identities unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
