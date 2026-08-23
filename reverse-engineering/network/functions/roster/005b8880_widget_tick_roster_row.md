# 0x005b8880 widget_tick_roster_row

| field | value |
|---|---|
| Original address | 0x005b8880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8880 |
| Resolved name | widget_tick_roster_row |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00618c20, FUN_0062fd90
**Referenced globals:** uRam006c45fe (room member count); cRam006c4fdb (local player index); cRam006c4fda (aux count); 0x639d50 (label format template); obj+2 (type); obj+3 (row index)
**Referenced strings:** (format template @0x639d50)
**Referenced opcodes:** —
**State vars:** uRam006c45fe; cRam006c4fdb

## Behavioral explanation
Per-frame widget update for a roster row: only active while row index < member count uRam006c45fe; resolves per-row resource (FUN_0062fd90), highlights the local player's row (cRam006c4fdb), and for item-type 0x06 formats a composed label (0x639d50 + count field) before blitting via FUN_005af1e0.

## Notes / uncertainty
Per-frame roster ROW draw; KEY count gate: draws only if row_index < uRam006c45fe (member count) - directly explains blank roster slots. Teardown via cRam006c4fd3(1/2), highlight cRam006c4fdb, type6=numbered player row (sprintf template 0x639d50 + cRam006c4fda+idx+1). Whether uRam006c45fe is the op0a/op06 count or a local mirror needs a runtime read; func_0x00109728 assumed sprintf.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
