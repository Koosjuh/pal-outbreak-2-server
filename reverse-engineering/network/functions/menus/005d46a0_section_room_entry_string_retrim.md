# 0x005d46a0 section_room_entry_string_retrim

| field | value |
|---|---|
| Original address | 0x005d46a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d46a0 |
| Resolved name | section_room_entry_string_retrim |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d1e80
**Callees:** —
**Referenced globals:** 0x701068+0x5ffc0 entity array
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks the entity list and trims the trailing token from the +100 string of room/member entries (kinds 0x04/0x06/0x07).

## Notes / uncertainty
RENAMED from entry_string_trim: on section-header(0x04) click, retrims the +0x64 packed string cursor of each room entry (0x06/0x07) in the section (bounded by 0x13 separators). in_t1_lo uninitialized edge case is a decompiler artifact; trim intent inferred; Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d46a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
