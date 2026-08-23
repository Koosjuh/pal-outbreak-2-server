# 0x005de170 loader_poll

| field | value |
|---|---|
| Original address | 0x005de170 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de170 |
| Resolved name | loader_poll |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8e00, FUN_005c9a00
**Callees:** FUN_005e7e30
**Referenced globals:** cRam00701060 (loader state); uRam00701050 (handle); uRam00701058 (result code); REG_RCNT0_COUNT (timer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00701060; uRam00701058

## Behavioral explanation
Pumps the async fetch: while busy, repeatedly calls FUN_005e7e30(handle) bounded by RCNT0 timer, mapping its status to codes 0/1/2/3 stored at uRam00701058 and clearing busy on completion/error.

## Notes / uncertainty
Time-sliced fetch pump: spin FUN_005e7e30 within RCNT0 budget 0x41, map status 0/1 in-progress, 2 done, 3 error to 0x701058, clear busy on 2/3. Step semantics + budget real-time span unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
