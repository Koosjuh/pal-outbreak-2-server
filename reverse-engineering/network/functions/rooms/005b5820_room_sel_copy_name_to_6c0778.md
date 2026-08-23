# 0x005b5820 room_sel_copy_name_to_6c0778

| field | value |
|---|---|
| Original address | 0x005b5820 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5820 |
| Resolved name | room_sel_copy_name_to_6c0778 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0260, FUN_005c0f00
**Referenced globals:** 0x6c0778 (0x15c-stride entry table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Read selected list index, commit a field into entry record at base 0x6c0778 (0x15c stride) via FUN_005c0260.

## Notes / uncertainty
String variant: strcpy(dst, src record[sel-1] @0x6cfb76) into UI entry @0x6c0778 — the room name/label. Helper indexes src with (idx-1)*0x144 (unlike scalar siblings). strcpy (func_0x00109eb8) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5820.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
