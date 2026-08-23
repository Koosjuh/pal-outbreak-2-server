# 0x00618600 net_endpoint_open_close_b

| field | value |
|---|---|
| Original address | 0x00618600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618600 |
| Resolved name | net_endpoint_open_close_b |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_006186e0
**Referenced globals:** iRam003908cc busy/guard flag; param+1 open-state; param+5 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam003908cc; *(param+1)

## Behavioral explanation
Variant of the transport open/close wrapper additionally gated on a global busy flag; opens/polls/closes a SN@P endpoint and maps the error code.

## Notes / uncertainty
Same SM as 618530 plus busy-guard iRam003908cc!=0 => -2, cfg block B=0x6543c0; called from create/enter SM. Guard owner and cfg A/B semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
