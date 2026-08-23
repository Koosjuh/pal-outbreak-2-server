# 0x005c9360 room_name_validate_advance

| field | value |
|---|---|
| Original address | 0x005c9360 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c9360 |
| Resolved name | room_name_validate_advance |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x701e20 (input name); 0x701068+0x4f7a0 (session name buf); 0x701080+0x1c/+0x11d (reference names); 0x701068+0x60dc7 (name-invalid flag); 0x701070+2 (sub-state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+2; 0x60dc7

## Behavioral explanation
Copies the room/host name (0x701e20) into the session name field and validates it against two reference strings; sets valid/invalid flag (0x60dc7) and advances room-create sub-state.

## Notes / uncertainty
Commits typed room name (0x701e20->sess+0x4f7a0), flags invalid if it equals either reserved reference (form+0x1c/+0x11d), advances screen step. Reference-string contents not read at runtime; libc thunks (strcpy/strcmp) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c9360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
