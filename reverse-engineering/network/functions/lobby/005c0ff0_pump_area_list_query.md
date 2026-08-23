# 0x005c0ff0 pump_area_list_query

| field | value |
|---|---|
| Original address | 0x005c0ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0ff0 |
| Resolved name | pump_area_list_query |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c2a70, FUN_005c2a90, FUN_005c3e50, FUN_005c4f40, FUN_005c4fd0
**Referenced globals:** 0x6ce5d4/0x6ce5dc area/channel table (10*0x24); 0x6ce616 desc field; 0x6cb9dc/0x6cb9d8 SM guard/step; 0x6febac conn
**Referenced strings:** NAME
**Referenced opcodes:** —
**State vars:** 0x6cb9dc guard; 0x6cb9d8 step

## Behavioral explanation
Async pump (guard 0x6cb9dc): on entry builds the area/channel list — initializes a 10-entry table 0x6ce5d4 (id,name via 2a70, desc via 2a90), then sends a 'NAME'(0x4e414d45) query for 10 entries and registers reply handler FUN_005c1220.

## Notes / uncertainty
4-state async pump for the 'NAME' area-list query; seeds 10 area records (0x144 stride @0x6ce5d4), sends via 001e094c, registers reply FUN_005c1220, delivers ok(0)/err(0xff) to callback 0x6cb9bc. 0x6cb9c0/c4 seq counters exact use unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
