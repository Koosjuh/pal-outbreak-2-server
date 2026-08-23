# 0x005be8c0 session_reopen

| field | value |
|---|---|
| Original address | 0x005be8c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be8c0 |
| Resolved name | session_reopen |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006075e0, FUN_006076c0
**Callees:** —
**Referenced globals:** 0x6cbbe0 phase; 0x6cbbe4 active; 0x6febac session ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbbe4 active; 0x6cbbe0 phase

## Behavioral explanation
Resets connect phase to 0, marks session active, and re-invokes transport open func_0x001dbe60(sessionCtx).

## Notes / uncertainty
Reconnect path: phase 0x6cbbe0=0, active 0x6cbbe4=1, calls transport open 001dbe60(ctx 0x6febac). No handler re-registration. open-vs-resume semantics of 001dbe60 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be8c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
