# 0x001c7680 recv_roomlist_entry_detail

| field | value |
|---|---|
| Original address | 0x001c7680 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c7680 |
| Resolved name | recv_roomlist_entry_detail |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3a60, FUN_001c3b10
**Referenced globals:** 0x365e0c cursor; 0x365e08 token; 0x365f7c per-room; 0x3619d0 id-table; 0x365e1e count; 0x365e1c member-count; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x365e0c cursor; conn+0xd next-state

## Behavioral explanation
Reply-0x1e/detail handler and list-teardown: on status=1 stores room token (0x365f7c) -> state 0x0a; on status=0 advances room cursor 0x365e0c and either continues (state 0x08) or finalizes the list (member-count clamp into 0x365e1c, state 0x0c); peer-gone path (fsm 4) purges the id table.

## Notes / uncertainty
op1e reply + list teardown: status1=store token(+0x15c), state 0x0a; status0=advance cursor, loop 0x08 or finalize displayed count 0x365e1c=min(room0.member,0xff) -> 0x0c; op_mode4 reply-gone purges id-table. Dual-token + room0-only count semantics uncertain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c7680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
