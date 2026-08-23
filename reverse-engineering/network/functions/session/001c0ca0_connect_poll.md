# 0x001c0ca0 connect_poll

| field | value |
|---|---|
| Original address | 0x001c0ca0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0ca0 |
| Resolved name | connect_poll |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40, FUN_001c19e0
**Callees:** FUN_001ee190, FUN_001ef1c0, FUN_001ef230, FUN_001ef2b0
**Referenced globals:** 0x35c3d8 mode/ctx; ctx+0x10 fd
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35c3d8

## Behavioral explanation
Non-blocking connect progress (mode==1): polls FUN_001ef1c0, resolves peer FUN_001ef230, opens socket FUN_001ef2b0; stores fd in ctx[4] or -1 on failure.

## Notes / uncertainty
Verified against raw: mode-1-only async connect completion poll over auth-ctx 0x35c3d8, fd latched at ctx[4], 3-way short-circuit (resolve/liveness/open) -> -1. Callee return conventions (FUN_001ef1c0 1=complete) inferred, not runtime-confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0ca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
