# 0x00621fe0 bg_scroll_animate

| field | value |
|---|---|
| Original address | 0x00621fe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00621fe0 |
| Resolved name | bg_scroll_animate |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622130
**Callees:** FUN_005f47e0
**Referenced globals:** 0x715298 screen struct ptr; 0x694410/0x694408 scroll deltas; 0x6496a0 render param
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00715298

## Behavioral explanation
Animates a scrolling background: advances two float phases (wrap at 512.0) and issues render/GS setup calls; only when struct+0x110 nonzero.

## Notes / uncertainty
Presentation-only: two float scroll phases (+0x18c/+0x190) wrapped at 512, GS/DMA setup + 2 draws. Guarded by obj+0x110. No protocol role.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00621fe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
