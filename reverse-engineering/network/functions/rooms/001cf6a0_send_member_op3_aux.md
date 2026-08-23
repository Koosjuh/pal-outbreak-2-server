# 0x001cf6a0 send_member_op3_aux

| field | value |
|---|---|
| Original address | 0x001cf6a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf6a0 |
| Resolved name | send_member_op3_aux |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cf7c0
**Callees:** FUN_001a7b70, FUN_001ab460, FUN_001cd010
**Referenced globals:** 0x3bfd8c enable table; 0x426860 flag; 0x42706c buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Guarded by table 0x3bfd8c[param_2]: attribute preset, flag at 0x426860, alloc 0x20 tag 3, then FUN_001cd010(param_2,-1,buf,3) to emit a type-3 member op.

## Notes / uncertainty
Twin of 0x1cf570 that ALSO emits: gated by 0x3bfd8c[area], allocs 0x20 tag3, then FUN_001cd010(area,-1,buf,3) type-3 member op. Which SN@P opcode 'type-3' maps to unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf6a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
