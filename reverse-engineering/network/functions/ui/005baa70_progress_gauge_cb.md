# 0x005baa70 progress_gauge_cb

| field | value |
|---|---|
| Original address | 0x005baa70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005baa70 |
| Resolved name | progress_gauge_cb |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00618c20
**Referenced globals:** 0x639e30/0x639e38 gauge coord tables; 0x006c552c fRam=gauge phase; 0x639e40/0x639e48 fmt strings; 0x006928c0 DAT=width scale
**Referenced strings:** 0x639e40; 0x639e48
**Referenced opcodes:** —
**State vars:** fRam006c552c

## Behavioral explanation
Progress-gauge display callback: self-destructs at phase>=200, else positions the bar sprite from tables 0x639e30/38 by +2, scales width by DAT_006928c0*phase, and on subtype 1 draws the centered percentage text.

## Notes / uncertainty
Gauge render cb: phase>=200 or state2 -> free node; state0 inits geometry from tables 0x639e30/38 by idx; fill node (idx1) scales width by 0x6928c0*phase and draws centered % text. FUN_00618c20(free) body undecoded; +0x24=0x200 open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005baa70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
