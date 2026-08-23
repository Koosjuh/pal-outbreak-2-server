# 0x005be690 session_open

| field | value |
|---|---|
| Original address | 0x005be690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be690 |
| Resolved name | session_open |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7270
**Callees:** —
**Referenced globals:** 0x6cbbe4 session-active guard; 0x6cbbc0 state callback ptr; 0x6cbbc4 user param; 0x6cbbe0 phase; 0x86f7f0 flag; 0x6febac session ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbbe4 session-active; 0x6cbbe0 connect phase

## Behavioral explanation
Starts a SN@P session: gated by cRam006cbbe4, latches the connect state-machine callback FUN_005be7b0 and param, then calls transport open func_0x001dbe60(sessionCtx).

## Notes / uncertainty
Begins SN@P session: guarded by 0x6cbbe4, installs session_connect_sm (0x6cbbc0), stores completion cb (0x6cbbc4), transport_connect(0x001dbe60). Returns -1 if already active.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
