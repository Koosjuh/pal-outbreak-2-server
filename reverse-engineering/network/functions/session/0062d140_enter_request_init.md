# 0x0062d140 enter_request_init

| field | value |
|---|---|
| Original address | 0x0062d140 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d140 |
| Resolved name | enter_request_init |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062d0f0
**Callees:** FUN_005b7fd0, FUN_00618b60, FUN_00627ae0, FUN_00628760
**Referenced globals:** +0x8 selection; +0xa/+0xc counters
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes the enter/register request task: allocs task (FUN_00628760), zeroes counters, kicks an internal request FUN_005b7fd0(0x23,...) carrying the selection byte.

## Notes / uncertainty
Enqueues internal request id 0x23 carrying selection byte (obj+8); bumps gen (obj+1), zeroes counters (obj+0xa/0xc). Whether 0x23 emits op04 vs op06 is decided downstream in FUN_005b7fd0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d140.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
