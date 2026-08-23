# 0x006069b0 lobby_conn_error_reset

| field | value |
|---|---|
| Original address | 0x006069b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006069b0 |
| Resolved name | lobby_conn_error_reset |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006063c0
**Callees:** FUN_005ac7d0, FUN_005b2410, FUN_00606f10, FUN_00618b60, FUN_00634550
**Referenced globals:** uRam00874f9c; uRam00870868; uRam0034359d
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
State-99 handler: on connection failure resets UI/menu subsystems (FUN_00634550 menu init, 005b2410, 005ac7d0, 00606f10) and flags 0x874f9c/0x870868.

## Notes / uncertainty
Connection-failure teardown: flags 0x874f9c=3/0x870868=1, ui reset, display-list reset, localized menu rebuild by lang 0x34359d, screen->mode7. Exact meaning of the two mode constants and func_0x001a7760 (audio/dma-stop by position) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006069b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
