# 0x001caa30 snap_send_reliable

| field | value |
|---|---|
| Original address | 0x001caa30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001caa30 |
| Resolved name | snap_send_reliable |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ca9d0, FUN_001cac50, FUN_001cac60, FUN_001df1d8
**Referenced globals:** 0x35b9e0=snap conn/session handle; 0x3688d0/d8=busy flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x3688d0/d8=in-flight guards

## Behavioral explanation
Guarded reliable-send: under the mutex, submits the buffer via FUN_001df1d8 with size flag 0x8000 (reliable) and maps failures to a conn-state error.

## Notes / uncertainty
Public reliable send: guard(0x3688d0==0 && 0x3688d8==0) else -16; under mutex FUN_001df1d8(handle,0x8000,buf,len); stores status to 0x3688d8; maps error via FUN_001ca9d0. 0x8000=reliable class. Exact d0-vs-d8 distinction inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001caa30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
