# 0x005b14b0 input_pressed

| field | value |
|---|---|
| Original address | 0x005b14b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b14b0 |
| Resolved name | input_pressed |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad030, FUN_005ad350, FUN_005ad530, FUN_005ad680, FUN_005ade20, FUN_005ae630, FUN_005ae9b0, FUN_005af780, FUN_005b09b0, FUN_005b0b40, FUN_005b0cd0, FUN_005b0f00, FUN_005b1190, FUN_005b1b10, FUN_005b1d20, FUN_005b1fa0, FUN_005b20c0, FUN_005b2260, FUN_005b29b0, FUN_005b33f0, FUN_005b3d80, FUN_005b3ed0, FUN_005b4860, FUN_005b4a50, FUN_005f4be0, FUN_005f60d0, FUN_005f6d20, FUN_005f7c80, FUN_005f8fc0, FUN_005f9540, FUN_005f9e50, FUN_005f9f60, FUN_005fa490, FUN_005fa990, FUN_005faa60, FUN_005fb060, FUN_005fb270, FUN_005fb860, FUN_005fec30, FUN_005fede0, FUN_005ff1b0, FUN_00600200, FUN_00600b60, FUN_00604180, FUN_006052f0, FUN_00606af0, FUN_00607bd0, FUN_00607cf0, FUN_00607dc0, FUN_00617910, FUN_00627f20, FUN_00628110, FUN_00628f70, FUN_006293f0, FUN_0062a6d0, FUN_0062a8c0, FUN_0062ab50, FUN_0062b020, FUN_0062bbc0, FUN_0062c580, FUN_0062cfd0, FUN_0062d1b0, FUN_0062d730, FUN_0062e2a0, FUN_0062e5b0
**Callees:** —
**Referenced globals:** 0x6c4618/0x6c4620 pad press/repeat masks; 0x6c462a pad button-char latch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Core button-edge predicate: given a button bitmask, returns true if that button is in the current press/repeat set (uRam006c4618/4620) or matches the button-char latch (cRam006c462a) via a large per-button decode.

## Notes / uncertainty
Central edge/repeat pad predicate (68 callers). Combined mask g_padEdge|(g_padRepeat&0xf000f) plus a 12-way bit->softkey(0x6c462a) alias ladder. Physical DualShock bit assignment inferred from softkey codes, not confirmed by live pad read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b14b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
