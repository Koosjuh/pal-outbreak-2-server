# 0x00606c80 reset_lobby_sm_flags

| field | value |
|---|---|
| Original address | 0x00606c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606c80 |
| Resolved name | reset_lobby_sm_flags |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606af0, FUN_006088b0
**Callees:** —
**Referenced globals:** 0x006c4b9e flag; 0x006c4b9f flag; 0x006c4faa mode; 0x006c4ba0 flag; 0x006c4ba1 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa

## Behavioral explanation
Zeroes four overlay flag bytes (6c4b9e/9f/ba0/ba1) and sets mode var 6c4faa=9.

## Notes / uncertainty
Zeroes lobby SM bytes 0x6c4b9e/9f/ba0/ba1 and sets top_screen 0x6c4faa=9 (connect/room-query dispatch). Concrete screen for top_screen==9 not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
