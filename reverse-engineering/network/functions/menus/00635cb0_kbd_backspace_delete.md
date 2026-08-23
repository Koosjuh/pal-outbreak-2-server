# 0x00635cb0 kbd_backspace_delete

| field | value |
|---|---|
| Original address | 0x00635cb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635cb0 |
| Resolved name | kbd_backspace_delete |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631030, FUN_00634ab0
**Callees:** FUN_00633fa0, FUN_006341d0, FUN_00634880, FUN_00634970, FUN_00637e10
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1d page-id; 0x260 preedit-len; 0x4c text-buffer; 0x4a bit0; 0x2f mode; 0x2a text-len; 0x2c preedit-len2; 0x32 exit-code; 0x248 status

## Behavioral explanation
Backspace/delete: removes a char from the committed buffer 0x4c or the preedit buffer 0x260 (per mode 0x2f), reindexes via 33fa0/341d0/37e10 and decrements length 0x2a.

## Notes / uncertainty
Backspace: delete-char / reset-composition / close per gate + edit-mode +0x2f (0/1/3). Two-buffer (committed +0x4c vs preedit +0x260). char-width/index helpers named from arithmetic.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635cb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
