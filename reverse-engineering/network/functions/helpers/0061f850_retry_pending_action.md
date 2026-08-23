# 0x0061f850 retry_pending_action

| field | value |
|---|---|
| Original address | 0x0061f850 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f850 |
| Resolved name | retry_pending_action |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_0061e710
**Referenced globals:** 0x715268 pending-action flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00715268

## Behavioral explanation
While a pending flag (iRam00715268) is set, retries FUN_0061e710 and clears the flag on success.

## Notes / uncertainty
Upgraded classified(Medium)->reconstructed(High). Per-frame deferred-action pump on g_pending_action 0x715268 (1=action A calls FUN_0061e710(0); other=action B); clears flag on non-zero return. Callee 0061e710 is always-true stub in this build, so flag self-consumes 1 frame later; real action opaque (stubbed).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f850.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
