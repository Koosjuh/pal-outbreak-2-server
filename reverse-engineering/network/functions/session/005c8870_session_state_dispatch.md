# 0x005c8870 session_state_dispatch

| field | value |
|---|---|
| Original address | 0x005c8870 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8870 |
| Resolved name | session_state_dispatch |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005cd730, FUN_005e02e0
**Referenced globals:** 0x642be0 (state handler fn-table); 0x701070+1 (session state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+1

## Behavioral explanation
Dispatches the per-state handler via table PTR_LAB_00642be0[session_state] (0x701070+1), bracketed by FUN_005e02e0/FUN_005cd730.

## Notes / uncertainty
Per-frame session pump: pre-hook, indexed indirect call PTR_00642be0[state@0x701070+1], post-hook. No bounds check on state index. Table contents/state map not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8870.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
