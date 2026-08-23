# 0x005f21f0 ui_draw_box

| field | value |
|---|---|
| Original address | 0x005f21f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f21f0 |
| Resolved name | ui_draw_box |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eacd0
**Callees:** FUN_005d9940, FUN_005efae0
**Referenced globals:** +0x186 draw mode; +0xe96b suppress; node+0x28/+0x2a pos, +0x1c/+0x1e size, +0x45 border, +0x54 color
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b

## Behavioral explanation
In draw mode pops the string buffer and calls draw primitive 0x5d9940 to render a node's filled box (x,y,x+w,y+h, style/color/border).

## Notes / uncertainty
Draw-pass leaf: paints container background/border rect via 5d9940. fill vs border-color field roles (+0x54/+0x58) inferred from arg order.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f21f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
