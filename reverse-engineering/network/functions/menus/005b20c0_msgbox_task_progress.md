# 0x005b20c0 msgbox_task_progress

| field | value |
|---|---|
| Original address | 0x005b20c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b20c0 |
| Resolved name | msgbox_task_progress |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1a30
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b14b0, FUN_005b1d10, FUN_005b8cf0, FUN_005b9060, FUN_005b9110, FUN_0062fea0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x430 phase; struct+0x431 timer; struct+0x5194 flag; struct+0x4096 flag

## Behavioral explanation
Modal progress/percentage box task (1a30 case 0xc): same 4-phase pattern as 1fa0 but also draws a centered numeric value (0062fea0 id 0x21); chooses panel by flags +0x5194/+0x4096.

## Notes / uncertainty
Modal progress box: same 4-phase idiom plus centered live counter (get_counter_value 0x21) drawn at x=0x140-w/2 y=0x177; init picks panel via flags +0x5194/+0x4096 (build 0x90 vs build_alt 0x8014). Glyph half-width fixed-point math approximated; flag/id semantics unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b20c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
