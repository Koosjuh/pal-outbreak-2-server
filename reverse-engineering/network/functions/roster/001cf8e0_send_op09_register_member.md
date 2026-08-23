# 0x001cf8e0 send_op09_register_member

| field | value |
|---|---|
| Original address | 0x001cf8e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf8e0 |
| Resolved name | send_op09_register_member |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ab460, FUN_001ab580, FUN_001cbc20, FUN_001cde00, FUN_001cf360
**Referenced globals:** 0x3c18b0 / 0x3c2250 member base tables; 0x498578/0x497d70 send buffers; sRam003433a8 mode flag
**Referenced strings:** —
**Referenced opcodes:** 0x09
**State vars:** sRam003433a8

## Behavioral explanation
Builds and sends the op09 register message: channel 0x1200/0x1300 (by param_1), alloc tag 9, encodes a member record from base table (0x3c18b0/0x3c2250) via FUN_001cde00; rolls back alloc on failure.

## Notes / uncertainty
Rewrote from classified->reconstructed. op09 register: base table 0x3c18b0(primary)/0x3c2250(alt by param_1), channel 0x1200/0x1300+slot*4, alloc tag 9 (ab460), buffer triad at slot*0x1468, encode+register via cde00; rollback (ab580) on encode==0. Flags: 0x80000000 reliable (online+param_5), 0x20000000 alt, |2 subtype; cde00 forwards low 29 bits as who/attr. Confirmed cde00 bit-decode + state mapping by reading its raw. Source record layout beyond bytes [0][1][4] not enumerated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf8e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
