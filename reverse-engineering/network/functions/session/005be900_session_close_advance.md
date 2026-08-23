# 0x005be900 session_close_advance

| field | value |
|---|---|
| Original address | 0x005be900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be900 |
| Resolved name | session_close_advance |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006075e0, FUN_006076c0
**Callees:** —
**Referenced globals:** 0x6cbbe4 active; 0x6cbbe0 phase; 0x6febac session ctx; 0x35b9e0 handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbbe4 active; 0x6cbbe0 phase; 0x35b9e0 handle

## Behavioral explanation
Advances session teardown: when active and not already in phase2, steps the phase, calls transport close func_0x001d4de0/0x001ca780 and invalidates the handle (0x35b9e0=-1).

## Notes / uncertainty
Polled teardown: steps phase 0->1->2, phase1 does transport_close(0x001d4de0)+cleanup+handle=-1. Returns 1 when quiescent/done, 0 while advancing. Does not clear 0x6cbbe4/buffers itself.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
