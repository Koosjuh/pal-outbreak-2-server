# 0x006250e0 input_button_to_mask

| field | value |
|---|---|
| Original address | 0x006250e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006250e0 |
| Resolved name | input_button_to_mask |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00625190
**Callees:** —
**Referenced globals:** 0x715da8 widget ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00715da8

## Behavioral explanation
Maps the current highlighted control char (at 0x715da8+0x49e: 'R'/'Q'/'O'/'P'/'('/')') to input bitmask bits (1/2/8/4/0x10/0x200) OR'd into *param.

## Notes / uncertainty
Maps highlighted soft-key glyph at (0x715da8)+0x49e to input bits (R=1,Q=2,P=4,O=8,'('=0x10,')'=0x200) OR'd into caller mask. Bit semantics confirmed by sole caller FUN_00625190's tests; glyph->physical-button mapping unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006250e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
