# 0x0062e2a0 lobby_exit_teardown_sm

| field | value |
|---|---|
| Original address | 0x0062e2a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e2a0 |
| Resolved name | lobby_exit_teardown_sm |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d950
**Callees:** FUN_005b14b0, FUN_005b8cf0, FUN_005b9110, FUN_00617a00, FUN_00637180
**Referenced globals:** 0x6c4b90 lobby block
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x10 exit-step; struct+0x16 countdown

## Behavioral explanation
Major-state 4 (exit) timed cleanup: countdown on struct+0x16, tears down UI (FUN_005b9110 0x4c) and resets 0x6c4b90 block via FUN_00617a00; FUN_005b8cf0(-0x52) restores prior screen.

## Notes / uncertainty
Renamed from state4-only: it is the full linear exit teardown SM (step@+0x10 0→4, countdown@+0x16). step0 session teardown+screen txn 0xae; 1 short wait 8f; 2 wait then arm 0x708; 3 wait-with-timeout on async 0x210; 4 free UI 0x4c + reset lobby_state_block 0x6c4b90. Sub-fn roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e2a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
