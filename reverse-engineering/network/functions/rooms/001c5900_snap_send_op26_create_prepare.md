# 0x001c5900 snap_send_op26_create_prepare

| field | value |
|---|---|
| Original address | 0x001c5900 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5900 |
| Resolved name | snap_send_op26_create_prepare |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_00109728, FUN_0010a050, FUN_001c3840, FUN_001c3c90, FUN_001c3ea0, FUN_001c4020, FUN_001ee590
**Referenced globals:** conn+0x9c seq; conn+0xa0 name-ptr; conn+0xa4 name-len; conn+0xd4/0xe4 data-ptr; 0x361a50 default-name; 0x35ccc8 data-base; conn+0xd next-state
**Referenced strings:** 0x361a50; 0x248830
**Referenced opcodes:** 0x26
**State vars:** conn+0x9c seq; conn+0xd next-state=0x20

## Behavioral explanation
Builds the create/prepare packet (opcode 0x26 = 'prepare' slot): sets up room name ptr (default 0x361a50 or conn+4) and data buffer (conn+8/0x35ccc8), emits seq(conn+0x9c)=0 + name string, transmits, advances to state 0x20.

## Notes / uncertainty
Create/slot PREPARE (op0x26): resolves name (override conn+4 or default 0x361a50) + data buf (conn+8 or 0x35ccc8), emits seq(=0)||name, next-state 0x20. Name-template 0x248830 contents undecoded; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
