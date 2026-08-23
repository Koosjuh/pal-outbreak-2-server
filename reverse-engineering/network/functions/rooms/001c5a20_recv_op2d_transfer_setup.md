# 0x001c5a20 recv_op2d_transfer_setup

| field | value |
|---|---|
| Original address | 0x001c5a20 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5a20 |
| Resolved name | recv_op2d_transfer_setup |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a338, FUN_001c3a60, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** conn+0x28 name; conn+0x29 name-len; conn+0x2a flag; conn+0x2c total-len; conn+0x34 recv-cursor; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x2d
**State vars:** conn+0x34 cursor; conn+0xd next-state

## Behavioral explanation
Reply parser (create/enter data transfer): reads status byte, validates echoed name (memcmp conn+0x28 vs local), reads total length into conn+0x2c and a flag into conn+0x2a; if nonzero sets window 0x2d2 and advances to state 0x21 (chunk receive) else branches 0x19/0x31/0x3f by fsm-state.

## Notes / uncertainty
Corrected prior offset error (word-idx vs byte): name=+0xa0, total=+0xb0, cursor=+0xd0. status1=arm chunk recv (window 0x2d2, state 0x21) or per-mode terminal; name-echo memcmp gate. Flag@+0xa8 meaning + op_mode enum unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5a20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
