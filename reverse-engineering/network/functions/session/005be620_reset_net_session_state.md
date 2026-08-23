# 0x005be620 reset_net_session_state

| field | value |
|---|---|
| Original address | 0x005be620 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be620 |
| Resolved name | reset_net_session_state |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0
**Callees:** FUN_005be060, FUN_005be080
**Referenced globals:** 0x6ca950 net-active; 0x6ca954/58/5c/60/62/64 state fields; 0x6cc101 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ca950 net-active; 0x6cc101

## Behavioral explanation
Zeroes the session/net state globals around 0x6ca950 (active flag, counters, sub-state) and runs the two paired init leaves.

## Notes / uncertainty
Cold-reset of net-session header cluster 0x6ca950..0x6ca964 (precedes slot table 0x6ca968) + flag 0x6cc101, then subinit leaves 005be060/080. Called from overlay init 005ac610/6f0. Per-field roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be620.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
