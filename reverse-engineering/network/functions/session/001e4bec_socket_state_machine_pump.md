# 0x001e4bec socket_state_machine_pump

| field | value |
|---|---|
| Original address | 0x001e4bec |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e4bec |
| Resolved name | socket_state_machine_pump |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e270c, FUN_001e2c7c, FUN_001e332c, FUN_001e366c, FUN_001e3ba8
**Callees:** FUN_001ef770, FUN_001ef830, FUN_001efda0
**Referenced globals:** PTR_0025b798 table (slot+4 state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0x7f est / 0xff0-0xff6 handshake / 0xff3 closing / -1 closed

## Behavioral explanation
TCP-like connection state machine: polls the lower layer (FUN_001ef830) for events and drives slot state through 0xff0..0xff6/0x7f (handshake, established, closing) transitions per event flags.

## Notes / uncertainty
stream lifecycle engine: poll (FUN_001ef830 event+count) then iterative state advance. Full enum documented: -1/0xff0..0xff6/0x7f, incl 0x7f<->0xff4 (data) & 0xff5<->0xff6 (accept) edge toggles matching connect/accept gates. Poll event bits beyond {0,4} + aux[2] unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e4bec.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
