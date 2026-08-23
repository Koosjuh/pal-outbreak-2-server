# 0x001e2424 socket_table_init

| field | value |
|---|---|
| Original address | 0x001e2424 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2424 |
| Resolved name | socket_table_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e2610
**Callees:** FUN_001010a8, FUN_00101c38, FUN_00109d70, FUN_00114ac8, FUN_001eb22c
**Referenced globals:** PTR_0025b798 socket table; 0x25b7a8 init-once counter; 0x25b7a0 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x25b7a8 init-once guard

## Behavioral explanation
Initializes the 0x40-entry socket table (PTR_DAT_0025b798, 0x24 stride): resolves device driver names on first call (FUN_00109d70), opens the driver (FUN_00101c38), and marks every slot free (0xffff) with an empty queue.

## Notes / uncertainty
Init-once (DAT_0025b7a8<2) driver open + reset of 64 sock entries (0x24 stride, id/port/peer=0xffff) + per-slot queue init. Roles of FUN_001010a8/00101c38 modes inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2424.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
