# 0x001e20a0 nanosleep

| field | value |
|---|---|
| Original address | 0x001e20a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e20a0 |
| Resolved name | nanosleep |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e2c7c, FUN_001e4728
**Callees:** FUN_00103de8, FUN_0010ea10, FUN_001e41fc
**Referenced globals:** 0x25b800 alarm sema id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Precise sleep: creates a sema, loops arming SetAlarm(handler e2058) and WaitSema, subtracting elapsed wall-clock (via e41fc) from the requested sec/usec until the interval expires.

## Notes / uncertainty
Precise sleep loop: arm SetAlarm+WaitSema, subtract measured elapsed. Tick constants 0x3da4/0xb8ec/0x3f interpreted, not HW-measured; SetAlarm<0 path leaks the sema.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e20a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
