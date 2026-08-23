# 0x005bc270 inroom_evt0b_set_countdown

| field | value |
|---|---|
| Original address | 0x005bc270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc270 |
| Resolved name | inroom_evt0b_set_countdown |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005bf230
**Referenced globals:** 0x6fb748 (countdown value); 0x6febfc (callback arg); 0x6cbc84 (UI status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-event 0xb: converts a tick value (payload+4)/30 into a seconds/frame countdown at 0x6fb748 and triggers FUN_005bf230(0x6febfc).

## Notes / uncertainty
Dispatcher case 0x0b: countdown = ticks(msg+4)/30 (frames->seconds) stored at 0x6fb748; clears UI status 0x6cbc84; triggers refresh FUN_005bf230(0x6febfc). /30=fps inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
