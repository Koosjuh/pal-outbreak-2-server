# 0x00607370 roomquery_state3_select

| field | value |
|---|---|
| Original address | 0x00607370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607370 |
| Resolved name | roomquery_state3_select |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606cf0
**Callees:** FUN_005af300, FUN_005b8cf0, FUN_005b9110, FUN_005c79d0, FUN_005c7a00, FUN_00606e40, FUN_00606f60, FUN_00606fa0, FUN_00607a10
**Referenced globals:** 0x00874410 staging; 0x00874500 record-src; 0x0070c048 room-name-src; 0x006c5497 sel-index; 0x006c50f0 input; 0x0070cd78 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070cd78; cRam006c5497; iRam006c50f0

## Behavioral explanation
State-3: waits on input/timer, polls 005c7a00 & 00607a10, and on selection copies the chosen record into staging 0x874410 (from 0x874500 stride0x104 and 0x70c048 stride0x158), then selects via 005c79d0.

## Notes / uncertainty
Verified against raw: multi-room selection SM; list-widget 00607a10 codes -2=back/-1=browse/0=confirm; copies meta 0x874500(stride0x104)->0x874410 and name 0x70c048(stride0x158)->0x874f3c, commits via 005c79d0(sel+1). func_0x001ee360 frame-gate semantics unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
