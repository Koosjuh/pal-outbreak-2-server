# 0x006064c0 lobby_conn_init

| field | value |
|---|---|
| Original address | 0x006064c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006064c0 |
| Resolved name | lobby_conn_init |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006063c0
**Callees:** FUN_005f4480
**Referenced globals:** uRam0070cdc8 (state); uRam0070cdca/cdcc (timers); uRam006c5520/uRam007012b0 (host cfg); 0x6c50ce
**Referenced strings:** server host/config @0x6c5520
**Referenced opcodes:** —
**State vars:** uRam0070cdc8

## Behavioral explanation
State-0 init: clears timers, sets state to 100, copies the server hostname/config string (func_0x001c0540) and kicks the setup routine FUN_005f4480.

## Notes / uncertainty
Pipeline state-0 (dispatcher FUN_006063c0): clears timer/attempt, formats host string, kicks net setup FUN_005f4480, parks state@0x70cdc8=100 (unhandled by dispatcher). KEY uncertainty: the async event that advances 100->1 (likely resolve callback) is not confirmed here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006064c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
