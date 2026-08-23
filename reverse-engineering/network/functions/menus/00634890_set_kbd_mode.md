# 0x00634890 set_kbd_mode

| field | value |
|---|---|
| Original address | 0x00634890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634890 |
| Resolved name | set_kbd_mode |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0
**Callees:** FUN_006322c0, FUN_00637540, FUN_00637690
**Referenced globals:** 0x715da8+0x1d (mode/charset); 0x715da8+0x20 (attr flags); 0x690d30 (mode-flag table); 0x690d10/0x690d11 (per-mode bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x1d; 0x715da8+0x20

## Behavioral explanation
Sets keyboard mode/charset (state+0x1d=param), loads mode attribute flags from DAT_00690d30, applies field-restriction bits (0x20/0x10) from the layout, and re-lays out.

## Notes / uncertainty
Sets mode(+0x1d), loads attr from DAT_00690d30[mode], ORs restrict bits 0x20/0x10 from layout gates, pulls per-mode byte pair 0x690d10/11. Full attr-bit semantics beyond 0x10/0x20 unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
