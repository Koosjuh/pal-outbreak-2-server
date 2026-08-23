# 0x00604c90 draw_create_room_button

| field | value |
|---|---|
| Original address | 0x00604c90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604c90 |
| Resolved name | draw_create_room_button |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_006048f0
**Referenced globals:** cRam006c5497/cRam006c5498 (cursor/room idx); 0x70b4d0 (status); &DAT_0064a000 (x-coord table); DAT_006931d8 (pulse rate)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c5497; cRam006c5498

## Behavioral explanation
Renders/animates a menu button with a pulsing alpha (sine of a rolling phase), enabling/greying it based on whether the member pool 0x694700 has a free slot and current member status < 2.

## Notes / uncertainty
Animated (sine-alpha pulse) button render job; enable-gate reads slot-status pool 0x70b4d0[(cursor)*0x38]<2 and pool 0x694700 query==0x32. Pool semantics (why 0x32 disables, >=2 occupied) inferred; no caller in corpus.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
