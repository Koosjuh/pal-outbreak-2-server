# 0x005c0920 copy_relay_record_0x6cd672

| field | value |
|---|---|
| Original address | 0x005c0920 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0920 |
| Resolved name | copy_relay_record_0x6cd672 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5ac0, FUN_005b5d20, FUN_005b6570
**Callees:** —
**Referenced globals:** 0x6cd672 source block (0x8a u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swapped copy of a 0x8a-entry (u16) block from 0x6cd672 into caller buffer param_1.

## Notes / uncertainty
CORRECTION: not byte-swapped — plain 0x114-byte (0x8a u16) copy from 0x6cd672 = relayed member_record size. Source identity (self member-relay record) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0920.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
