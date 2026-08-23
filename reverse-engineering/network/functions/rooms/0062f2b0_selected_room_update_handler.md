# 0x0062f2b0 selected_room_update_handler

| field | value |
|---|---|
| Original address | 0x0062f2b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f2b0 |
| Resolved name | selected_room_update_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c01d0
**Referenced globals:** 0x6c4600 selected-room; 0x6c0762 per-room field; 0x6c0606 per-room field; 0x6c4ba0 substate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90 phase(==0x0e)

## Behavioral explanation
Reply callback (guard cRam006c4b90==0x0e): bumps ba0; status 0 updates selected-room entry 0x6c0762 (via FUN_005c01d0), else zeroes its 0x6c0606 field.

## Notes / uncertainty
Already fully reconstructed. Screen-0x0e join/update cb; always step++, success re-fetches name at (sel-1)*0x15c+0x6c0762, failure zeroes sel*0x15c+0x6c0606. Open: (sel-1) vs sel indexing asymmetry and parallel 0x6c0606 table unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f2b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
