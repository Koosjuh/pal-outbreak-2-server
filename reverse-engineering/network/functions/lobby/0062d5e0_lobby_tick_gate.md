# 0x0062d5e0 lobby_tick_gate

| field | value |
|---|---|
| Original address | 0x0062d5e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d5e0 |
| Resolved name | lobby_tick_gate |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005aec70, FUN_005af1a0, FUN_0062d640
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+1 busy-flag

## Behavioral explanation
Per-frame tick entry: if FUN_005aec70()==0 and struct+1==0 run the major dispatcher FUN_0062d640, then FUN_005af1a0(struct,1).

## Notes / uncertainty
Per-frame tick: if FUN_005aec70()==0, run major dispatch FUN_0062d640 when ctx+1==0, then always FUN_005af1a0(ctx,1). Straightforward gate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d5e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
