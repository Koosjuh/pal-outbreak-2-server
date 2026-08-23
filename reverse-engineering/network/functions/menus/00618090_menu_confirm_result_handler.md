# 0x00618090 menu_confirm_result_handler

| field | value |
|---|---|
| Original address | 0x00618090 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618090 |
| Resolved name | menu_confirm_result_handler |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c4b90 (mode); 0x6c4fbb (screen-id, cleared); 0x6c4b9f (counter); 0x6c5521 (confirm flag=1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb==0x1a gate; 0x6c5521 result

## Behavioral explanation
Guarded confirm-callback (active only when screen-id cRam006c4fbb==0x1a and mode cRam006c4b90!=6): on non-zero choice sets flag 0x6c5521 and invokes FUN_005be9a0(0x6c517c); else bumps a counter.

## Notes / uncertainty
Confirm callback gated on lobby_state_block screen_id!=6 && pending_tag(0x6c4fbb)==0x1a; choice 0=advance screen_major(0x6c4b9f), else set 0x6c5521 + teardown FUN_005be9a0(0x6c517c). No recovered caller; accept/cancel labeling inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618090.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
