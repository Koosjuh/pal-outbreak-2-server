# 0x001d0400 send_op0b_small

| field | value |
|---|---|
| Original address | 0x001d0400 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0400 |
| Resolved name | send_op0b_small |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001a1750, FUN_001a7b70, FUN_001ab460, FUN_001cbc20, FUN_001cce80
**Referenced globals:** conn+0x878/+0x890 send buffers; cRam00343577 offline-mode
**Referenced strings:** —
**Referenced opcodes:** 0x0b
**State vars:** cRam00343577

## Behavioral explanation
Channel (param_2*8 + 0x3000), attribute preset with key0xc=1, alloc tag 0xb (8 bytes), sets buffers at param_1+0x70 and opens a reliable send FUN_001cce80(param_2,-1,buf,3)/offline FUN_001a1750.

## Notes / uncertainty
Builds/sends 8-byte op-0x0b control msg: channel ctx param_2*8+0x3000, control-class attr preset (0xc=1,0x62=0,0x66=0), alloc tag 0xb, online FUN_001cce80 / offline FUN_001a1750 fork on cRam00343577. op0b role (control/ack) unconfirmed; no callers recorded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0400.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
