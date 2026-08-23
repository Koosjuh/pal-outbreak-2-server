# 0x001c6e80 recv_roomlist_header

| field | value |
|---|---|
| Original address | 0x001c6e80 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6e80 |
| Resolved name | recv_roomlist_header |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3a60, FUN_001c3b10
**Referenced globals:** 0x365e04 total; 0x365e00 cursor; 0x365e0c/0x365e10/0x365e12/0x365e18/0x365e1a counters; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x365e0c list-write-idx; conn+0xd next-state

## Behavioral explanation
Reply-0x1c handler: on status=1 reads two u32 (0x365e04 total, 0x365e00 cursor) and inits list counters, advances to state 0x06; on status=0 finalizes to state 0x0c (fsm 5) or 0x08.

## Notes / uncertainty
op1c reply header: status1=read total(0x365e04)+token(0x365e00), init page ctrs, next 0x06; status0=empty -> 0x0c(op_mode5)/0x08. 0x365e10 role undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6e80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
