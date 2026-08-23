# 0x00637ba0 kbd_symbol_excluded

| field | value |
|---|---|
| Original address | 0x00637ba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637ba0 |
| Resolved name | kbd_symbol_excluded |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_006379e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Symbol/char filter: returns false for specific codes (0xff62/0xff63-style -0x9e/-0x9d, 0x25, 0xb7) else true.

## Notes / uncertainty
Renamed from kbd_symbol_allowed: returns false for 4 reserved glyphs (0xFF62,0xFF63,0x25,0xB7), callers invert. Glyph identities inferred; values exact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637ba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
