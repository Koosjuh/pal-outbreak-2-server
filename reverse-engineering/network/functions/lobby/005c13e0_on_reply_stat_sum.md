# 0x005c13e0 on_reply_stat_sum

| field | value |
|---|---|
| Original address | 0x005c13e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c13e0 |
| Resolved name | on_reply_stat_sum |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c7d00
**Referenced globals:** 0x6cf286 accumulated count; 0x6cba05 SM signal
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cba05

## Behavioral explanation
Reply handler: sums a u16 field (+0x14, 0x28 stride) across reply entries into 0x6cf286, then signals the stat-query SM (0x6cba05).

## Notes / uncertainty
List-reply completion cb: sums u16@+0x14 over 0x28-stride entries (matches room_record current-players) into 0x6cf286; signals 0x6cba05=1 on last page (guard param_1[1]==1&&u16!=0 = pagination), =2 on abort tag 0x27. No direct caller edge / no runtime trace -> Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c13e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
