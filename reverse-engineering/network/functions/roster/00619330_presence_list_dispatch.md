# 0x00619330 presence_list_dispatch

| field | value |
|---|---|
| Original address | 0x00619330 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619330 |
| Resolved name | presence_list_dispatch |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3790
**Callees:** FUN_006193e0, FUN_00619430, FUN_006195b0, FUN_00619680, FUN_00619750
**Referenced globals:** cRam006c5490 machine step; 0x6c4b90 machine context
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c5490

## Behavioral explanation
Step dispatcher for a presence/name-list update machine, branching on cRam006c5490 (0..4) to reset / enumerate / prune / delay / net-tick sub-handlers.

## Notes / uncertainty
Clean phase dispatcher on cRam006c5490 (0..4) into the 5 presence sub-handlers; only phase4 returns 1 (complete). 0x6c4b90 used as this machine's context; whether it truly aliases lobby_state_block is unproven. Client-side presence list, not on SN@P wire (inferred).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
