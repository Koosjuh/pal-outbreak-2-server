# 0x005c05c0 on_reply_create_enter_op6e

| field | value |
|---|---|
| Original address | 0x005c05c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c05c0 |
| Resolved name | on_reply_create_enter_op6e |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf180, FUN_005c1ff0, FUN_005c7d00, FUN_005c7e30
**Referenced globals:** 0x6ff2b1 room-owned state (=1); 0x6ff2b2 aux flag (=1); 0x6cbc84 UI ok/err status; 0x6cbc7c/0x6cbc7e/0x6cbc80 UI reply fields; 0x6febf4 timer(=0x96)
**Referenced strings:** —
**Referenced opcodes:** 0x6e
**State vars:** 0x6ff2b1; 0x6ff2b2; 0x6cbc84

## Behavioral explanation
Reply handler for the create/enter (op6e) request: on success sets room-owned state 0x6ff2b1=1 and 0x6ff2b2=1, timer 0x96; on error 0x27 sets fail status and inspects reply field +4==0xf; stores UI status and triggers redraw.

## Notes / uncertainty
op6e reply cb: on 0x00 commits room2, sets timer 0x96 and the create-boundary ownership lock 0x6ff2b1=1 (+0x6ff2b2=1); on 0x27 latches error and inspects +4==0xf (name-taken/full class, meaning inferred). Always sets dialog mode + redraw.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c05c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
