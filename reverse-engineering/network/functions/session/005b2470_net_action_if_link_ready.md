# 0x005b2470 net_action_if_link_ready

| field | value |
|---|---|
| Original address | 0x005b2470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2470 |
| Resolved name | net_action_if_link_ready |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005acea0, FUN_005addb0, FUN_005b3790, FUN_005fb270, FUN_00617a50
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If the link/connection status (001a6800) is 0 or 5, issue a network request (001b1a30) with the passed selector.

## Notes / uncertainty
Submits transport request (001b1a30) only when link-state (001a6800) is 0 or 5. Exact enum of states 0/5=idle/ready is inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
