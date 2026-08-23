# 0x005fc0c0 roomlist_reply_refresh

| field | value |
|---|---|
| Original address | 0x005fc0c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc0c0 |
| Resolved name | roomlist_reply_refresh |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b9110, FUN_005ba940, FUN_005baa00, FUN_005baa60, FUN_005be9a0, FUN_005bff80, FUN_005c01d0, FUN_005c0210, FUN_005c0260, FUN_005c0370, FUN_005c0860, FUN_005c09c0, FUN_005c1c10
**Referenced globals:** cRam006c4fbb pending-req state; 0x6c4602 room count; 0x6c0760 room-slot table (stride 0x15c); cRam006c4b90 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==9 gate); cRam006c4b9e list gen

## Behavioral explanation
Room-list reply handler (pending-state 9): parses reply sub-byte; on full-list rebuilds the room-slot table (0x6c0760, count 0x6c4602) via per-field decoders, else handles sub 0x0a/0x0b.

## Notes / uncertainty
op49 room-list reply handler (pending 0x6c4fbb==9): kind0 rebuilds 0x6c0760 rows (count 0x6c4602) via 7 per-field decoders incl flags +0x14/0x6c0774; kind2 sub 0x0a/0x0b incremental; else error dialog. Bumps list-gen 0x6c4b9e (redraw trigger). Which decoded word carries cur/max player count needs a wire/PINE trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc0c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
