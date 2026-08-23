# 0x005c4330 get_signin_result

| field | value |
|---|---|
| Original address | 0x005c4330 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4330 |
| Resolved name | get_signin_result |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062cc60
**Callees:** —
**Referenced globals:** 0x6fbe50/52/54 (result fields); 0x6fbe57 (auth result byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006fbe57

## Behavioral explanation
Reads the sign-in result out (three shorts 0x6fbe50/52/54 + result byte 0x6fbe57) into the caller's pointers.

## Notes / uncertainty
Copies sign-in result record: u16x3 @0x6fbe50/52/54 + u8 status @0x6fbe57 to caller ptrs. Field semantics of the 3 shorts unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
