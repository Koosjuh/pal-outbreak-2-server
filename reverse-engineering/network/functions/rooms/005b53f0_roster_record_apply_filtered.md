# 0x005b53f0 roster_record_apply_filtered

| field | value |
|---|---|
| Original address | 0x005b53f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b53f0 |
| Resolved name | roster_record_apply_filtered |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c4b90, FUN_005f50d0
**Referenced globals:** 0x6c4b90 cRam006c4b90 area filter; 0x6c7c2c player-slot table (4 x 0x3b0); 0x6c7c3c per-slot name
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90

## Behavioral explanation
Registered command handler (selector id 5): parses an incoming room/player record (0x5c4b90) and applies it (0x5f50d0), area-filtered, scanning the 4 player slots at 0x6c7c2c (stride 0x3b0).

## Notes / uncertainty
Selector-5 S->C room/roster record apply, mode-gated on screen_id 0x6c4b90 (2/4/0xc/0xe); in-room modes 4/0xc require the record name to match a seated 0x6c7c2c slot (stride 0x3b0) before applying. Explains why records for non-seated players drop. type 4 vs 0xc semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b53f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
