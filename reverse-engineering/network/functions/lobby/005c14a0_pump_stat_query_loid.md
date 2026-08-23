# 0x005c14a0 pump_stat_query_loid

| field | value |
|---|---|
| Original address | 0x005c14a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c14a0 |
| Resolved name | pump_stat_query_loid |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf1e0, FUN_005c3e50
**Referenced globals:** 0x6cf27c stat table (6*0x144); 0x6fed70/0x6fec28 stat records; 0x6cba04/0x6cba00 SM guard/step; 0x6cb9ec page idx; 0x6febac conn
**Referenced strings:** LOID; STAT
**Referenced opcodes:** —
**State vars:** 0x6cba04 guard; 0x6cba00 step; 0x6cb9ec page

## Behavioral explanation
Async pump (guard 0x6cba04): initializes a 6-entry stat table (0x6cf27c/0x6fed70/0x6fec28) then loops (up to 4 pages) sending a 'LOID'(0x4c4f4944)+'STAT'(0x53544154) query and registering reply handler FUN_005c13e0.

## Notes / uncertainty
5-state pump paging (4x) the LOID+STAT query for 6 rooms of current area; LOID ptr=(area-1)*0x24+0x6fec28, per-page selector 0x640500+(page*2+2)*4, reply FUN_005c13e0. STAT field layout + 0x7006a8 arg not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c14a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
