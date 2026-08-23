# 0x0062dae0 roomlist_select_scan

| field | value |
|---|---|
| Original address | 0x0062dae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062dae0 |
| Resolved name | roomlist_select_scan |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d950
**Callees:** —
**Referenced globals:** 0x6c0760 room table; 0x6c076e entry-state; 0x6c0774 room-attr bits(0x10000/0x20000); 0x6c4600 selected-room; 0x6c4602 room count; 0x343571 mode flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf next-state (2/3); struct+0x9a0 retry timer

## Behavioral explanation
Scans room table 0x6c0760 (up to uRam006c4602 entries) for a joinable room: entry-state byte==3 and per-room flag +0x9ac==0, testing attribute bits 0x20000/0x10000 in 0x6c0774 vs cRam00343571; picks room -> sets 0x6c4600 and +0xf to 2(join) or 3(enter).

## Notes / uncertainty
Leaf two-pass scanner; attr bits 0x10000=open/0x20000=create-target, mode 0x343571==2=create; latches 0x6c4600 then major-state 2/3/4. goto structure faithfully reproduced. Entry-state 3-vs-1 origin (server vs post-decode) and full attr bitfield unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062dae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
