# 0x00631880 softkbd_cursor_advance

| field | value |
|---|---|
| Original address | 0x00631880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631880 |
| Resolved name | softkbd_cursor_advance |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00634160, FUN_00637e90
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x260 IME buffer; +0x2a main cursor; +0x4c main buffer; +0x28 dirty; +0x248 result code

## Behavioral explanation
End/home key (0x4d): moves the main-buffer cursor (+0x2a) to buffer length; marks dirty, result 1.

## Notes / uncertainty
Renamed from cursor_to_end. Caret-right (0x4d): advance main caret to next-glyph index (FUN_00634160) if caret<len; marks dirty, result 1. Advance-by-one vs to-end depends on FUN_00634160 internals (undecided).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
