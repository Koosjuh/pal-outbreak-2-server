# 0x0061d6a0 dnas_connect_state_machine

| field | value |
|---|---|
| Original address | 0x0061d6a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061d6a0 |
| Resolved name | dnas_connect_state_machine |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061fd70, FUN_00620b60, FUN_00624c70
**Callees:** FUN_001f46e0, FUN_0061d690, FUN_0061e630, FUN_0061e640, FUN_0061e650, FUN_0061e680, FUN_0061e6e0, FUN_0061e7f0, FUN_0061ea30, FUN_0061f0f0, FUN_0061f4b0
**Referenced globals:** cRam007152e2 connect-state; sRam007152e4 state timer; uRam007152e8 status word
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e2; sRam007152e4

## Behavioral explanation
Screen-driven connection/auth state machine keyed on cRam007152e2: runs the DNAS/SN@P connect sequence (func_0x001f5630 connect, 001f4680, 001f46e0), decrementing per-state timers and transitioning through connecting/error/retry states.

## Notes / uncertainty
Char-coded DNAS/session connect+auth SM (0x7152e2); libnet 001f5630/4680/46e0/5650; terminals 0x05=1,0x15/0x29=-1; retry cluster 0x14/0x1e/0x23/0x28. State→UI-phase mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061d6a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
