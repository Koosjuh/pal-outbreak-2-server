# 0x0062d950 lobby_state2_dispatch

| field | value |
|---|---|
| Original address | 0x0062d950 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d950 |
| Resolved name | lobby_state2_dispatch |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d640
**Callees:** FUN_0062d9f0, FUN_0062dae0, FUN_0062dc40, FUN_0062de90, FUN_0062e2a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state (0-4)

## Behavioral explanation
Major-state 2 sub-dispatcher on struct+0xf: 0->d9f0(roomlist init), 1->dae0(list scan), 2->dc40(create), 3->de90(enter/roster), 4->e2a0(exit).

## Notes / uncertainty
Exact if/else ladder on state+0xf (0=init,1=scan,2=create,3=enter,4=exit). Enter(3)/exit(4) handler internals out of batch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d950.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
