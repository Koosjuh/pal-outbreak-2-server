# 0x005f54d0 chatlog_render_window

| field | value |
|---|---|
| Original address | 0x005f54d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f54d0 |
| Resolved name | chatlog_render_window |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f84c0, FUN_005fec30, FUN_00601d50, FUN_00602340
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005f4ed0, FUN_005f4fd0, FUN_005f5300
**Referenced globals:** iRam003435d4+0xc9358/935c/9360(head/scroll/tail); 0x6c54d0/54e0(per-row cache); 0x649718
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c50fb; +0xc935c scroll

## Behavioral explanation
Renders the visible chat-log window: computes scroll position, then draws each sender name + message line with color.

## Notes / uncertainty
Draws visible log window; mode 0/1/2 -> rows 10/5/11, baseY 84/96/100. Live mode auto-follows (view=head-rows clamped to tail); history mode scrolls via FUN_005f4ed0/4fd0. Seeds per-row caches 0x6c54d0(attr) / 0x6c54e0(x) for the node callback. FP pixel geometry approximate (Ghidra float regs inferred).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f54d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
