# 0x00637690 kbd_snap_cursor_special_keys

| field | value |
|---|---|
| Original address | 0x00637690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637690 |
| Resolved name | kbd_snap_cursor_special_keys |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631100, FUN_006312c0, FUN_00631560, FUN_00631670, FUN_00634890, FUN_00635bb0, FUN_00635f80, FUN_00636f90, FUN_006375d0
**Callees:** —
**Referenced globals:** 0x715da8 state struct; 0x692401/0x692408 cursor-offset table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1f key-type; 0x24/0x25 cursor

## Behavioral explanation
Snaps cursor 0x24/0x25 to fixed positions for special key-types 4 and 5 (using DAT_00692401/uRam00692408 offsets).

## Notes / uncertainty
Snaps cursor +0x24/+0x25 for key-types 4 (col=u692408,row=tab692401[8]) and 5 (5,0); others untouched. Stride-2 row table shape unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
