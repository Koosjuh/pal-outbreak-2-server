# 0x0062d640 lobby_major_state_dispatch

| field | value |
|---|---|
| Original address | 0x0062d640 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d640 |
| Resolved name | lobby_major_state_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d5e0
**Callees:** FUN_005f4b80, FUN_005f4be0, FUN_0062d730, FUN_0062d810, FUN_0062d950, FUN_0062e3c0, FUN_0062e8d0
**Referenced globals:** struct+0x992 fail-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xe major-state (0-4)

## Behavioral explanation
Top-level lobby/room state dispatcher on struct+0xe: 0->d730(area/roomlist), 1->d810, 2->d950, 3->e3c0, 4->e8d0(stub); state3 sets +0x992 fail-flag if FUN_005f4be0==0.

## Notes / uncertainty
Central major-state dispatcher ctx+0xe 0-4; states 1-3 run pre-step pump(005f4b80)+probe(005f4be0); state3 sets fail flag +0x992 on probe==0 then FUN_0062e3c0. Phase-handler roles (d730/d950/e3c0/e8d0) not labeled; pump/probe names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d640.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
