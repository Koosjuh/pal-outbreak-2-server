# 0x0062cf50 enter_submachine_dispatch

| field | value |
|---|---|
| Original address | 0x0062cf50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cf50 |
| Resolved name | enter_submachine_dispatch |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062aeb0, FUN_0062c1d0
**Callees:** FUN_0062cfd0, FUN_0062d0f0, FUN_0062d380
**Referenced globals:** 0x695d40 enter submachine selector
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00695d40

## Behavioral explanation
Dispatcher on cRam00695d40 (0..2) into the enter/register submachine (select -> request-build -> send steps).

## Notes / uncertainty
3-way dispatch on step byte 0x695d40 into select(0)/send(1)/poll(2) of the enter/register SM; step 2 passes &0x695d40 as ctx. select/send/poll labels inferred from call topology.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cf50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
