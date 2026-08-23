# 0x006231b0 screen_handler_link

| field | value |
|---|---|
| Original address | 0x006231b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006231b0 |
| Resolved name | screen_handler_link |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_005b24c0, FUN_0061f0d0, FUN_0061f1d0, FUN_0061f340, FUN_0061f3b0, FUN_00623800
**Referenced globals:** 0x715298 screen struct ptr; 0x3433b8 pad/link bits; 0x35b746 counter; 0x35b74d status; 0x7152e1 next-screen
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** substate @ struct+1; uRam007152e1

## Behavioral explanation
Screen handler reading link/controller status (func_0x001c0c50, sRam0035b746/0035b74d) and running exit anim FUN_00623800; branches to substates 2/3.

## Notes / uncertainty
Struct-family controller/link poll (func_0x001c0c50); on result 4/2 seeds GLOBAL SM 0x7152e1=3/2 and lobby handoff FUN_005b24c0. Bridges the two handler families. Poll-result semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006231b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
