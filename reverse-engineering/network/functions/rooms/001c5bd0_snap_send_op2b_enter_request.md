# 0x001c5bd0 snap_send_op2b_enter_request

| field | value |
|---|---|
| Original address | 0x001c5bd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5bd0 |
| Resolved name | snap_send_op2b_enter_request |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001c3ea0, FUN_001c4020, FUN_001ee590
**Referenced globals:** conn+0xa0 name-ptr; conn+0xd0; conn+0xac; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x2b
**State vars:** conn+0xd next-state=0x22

## Behavioral explanation
Emits opcode 0x2b carrying room name (conn+0xa0), a u32 (conn+0xd0) and u16 (conn+0xac); advances to state 0x22 — enter/join-with-payload request.

## Notes / uncertainty
ENTER (op0x2b): body name||u32(+0xd0 handle)||u16(+0xac attr/pw), next-state 0x22. u32/u16 field semantics inferred (likely room handle + slot/pw).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5bd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
