# 0x00626e70 menu_datafetch_screen_step

| field | value |
|---|---|
| Original address | 0x00626e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00626e70 |
| Resolved name | menu_datafetch_screen_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e7f0, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f340, FUN_0061f3b0, FUN_0061f4b0, FUN_0061f600, FUN_0061f760
**Referenced globals:** 0x365df8 fetch-buf-a; 0x365dcc fetch-buf-b; 0x86f864 display-buf; 0x7152d0 done-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1 screen-phase; sRam007152e4 timer; sRam007152e6 result-code; uRam007152d0

## Behavioral explanation
Multi-phase menu screen (states 'd'..'h' plus 0x01-0x0e) that polls an async fetch (func_0x001c3380) and copies result blocks from iRam00365df8/iRam00365dcc into buffer 0x86f864 for display.

## Notes / uncertainty
Async news/notice fetch screen (start func_0x001c3250, poll 001c3380); copies 0x365df8(0x1000)/0x365dcc(0xfec) into 0x86f864, sets done flag 0x7152d0. Sibling of FUN_00625670 (shared API + status->msg table). Content domain inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00626e70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
