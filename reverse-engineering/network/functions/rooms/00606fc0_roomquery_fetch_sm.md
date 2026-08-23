# 0x00606fc0 roomquery_fetch_sm

| field | value |
|---|---|
| Original address | 0x00606fc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606fc0 |
| Resolved name | roomquery_fetch_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606cf0
**Callees:** FUN_005af2f0, FUN_005af300, FUN_005b8cf0, FUN_005b9110, FUN_005c78e0, FUN_005c7900, FUN_005c79d0, FUN_005c7a00, FUN_005c7ba0, FUN_005c7bd0, FUN_00606e40, FUN_00606f60, FUN_00606fa0, FUN_00607a10, FUN_00618b60
**Referenced globals:** 0x00874f35 phase; 0x00870868 substep; 0x008744f8 room-count; 0x0070c000 room-records; 0x006c5490 txn-block
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00874f35; cRam00870868; bRam008744f8

## Behavioral explanation
State-0 room-query screen: polls network (005c7900/005c7a00), on results copies bRam008744f8 room records (0x158 stride @0x70c000) via 005c7bd0 and drives retry/jingle via 00607a10.

## Notes / uncertainty
Verified against raw: name in record is roomquery_fetch_sm (task label state0 is a subset). Phase-gate 0x874f35{0,1,2}=browse else abnormal; 4-state fetch, records copied to 0x70c000 stride 0x158, auto-select if count<2. Poll polarity of 005c7900 vs 005c7a00 not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606fc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
