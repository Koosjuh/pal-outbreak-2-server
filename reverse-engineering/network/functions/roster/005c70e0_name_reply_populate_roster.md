# 0x005c70e0 name_reply_populate_roster

| field | value |
|---|---|
| Original address | 0x005c70e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c70e0 |
| Resolved name | name_reply_populate_roster |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf280
**Referenced globals:** 0x6fec18 (id table, 0x24 stride); 0x6ce5de (member table, 0x144 stride); 0x6d2158 (member count); 0x6cbc7e/0x6cbc84 (redraw flags); 0x6d215a/0x6d215c (cursor ids)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6d2158 (roster count)

## Behavioral explanation
NAME-reply handler: iterates reply entries, resolves each id via FUN_005bf280, and fills the member/id roster tables, then pokes redraw (FUN_005bdfe0(0xf)).

## Notes / uncertainty
op48 name-query reply cb: iterates entries (count@+8, stride 0x24, id@+0x20), looks up the 10-slot NAME roster (0x6fec28 via FUN_005bf280), fills 0x6fec18/0x6ce5de, sets panel mode, fires UI 0xf. NOTE distinct roster (10-slot name registry) from the 30-slot member roster 0x6fee6c. Decompiler places entry+=0x24 inside match branch (preserved verbatim, likely artifact).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c70e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
