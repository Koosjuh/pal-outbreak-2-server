# 0x006080d0 render_room_detail

| field | value |
|---|---|
| Original address | 0x006080d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006080d0 |
| Resolved name | render_room_detail |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b7cd0, FUN_0062fea0
**Referenced globals:** 0x0070c048 room-name; 0x0070c058 room-data; 0x006c5497 sel-index; 0x008744f8 total; 0x0064a0f8 fmt; 0x0064a100 fmt
**Referenced strings:** 0x64a0f8 (format); 0x64a100 (format)
**Referenced opcodes:** —
**State vars:** cRam006c5497; uRam008744f8

## Behavioral explanation
Draw callback: renders selected room's name (0x70c048 stride0x158), fields 70c002/70c004, and 'x/y' count from sel 6c5497 vs total 8744f8, using text/box primitives.

## Notes / uncertainty
Selected-room detail card (table 0x70c000 stride 0x158): markup body, centred title, two labelled fields (+0x02/+0x04), sel+1/total readout. Float coords decoded (120.0,312.0). Field semantics inferred; format text not fetched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006080d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
