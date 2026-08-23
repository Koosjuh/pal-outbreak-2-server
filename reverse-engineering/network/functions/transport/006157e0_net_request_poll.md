# 0x006157e0 net_request_poll

| field | value |
|---|---|
| Original address | 0x006157e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006157e0 |
| Resolved name | net_request_poll |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060e060, FUN_0060eba0, FUN_0060ec60, FUN_0060ed40, FUN_0060ee80, FUN_0060eff0
**Callees:** FUN_00616b40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Advances the async net request one step (FUN_00616b40(1) poll).

## Notes / uncertainty
Per-frame pump: tail-call FUN_00616b40(1) advance-step. Engine body (fd DAT_00654208, mode0 close/mode1 poll) inferred from sibling thunk; status dropped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006157e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
