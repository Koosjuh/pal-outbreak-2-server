# 0x00627a80 roster_set_selected_local

| field | value |
|---|---|
| Original address | 0x00627a80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627a80 |
| Resolved name | roster_set_selected_local |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627f20, FUN_0062d1b0
**Callees:** —
**Referenced globals:** 0x7154e0 selected-id; 0x7154f0 selected-slot
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fdf selection-pending

## Behavioral explanation
Stores a selected 16-byte member id into 0x7154e0 with slot index sRam007154f0, and raises the selection-pending flag uRam006c4fdf.

## Notes / uncertainty
Setter: stores selected member id (0x7154e0)+slot (0x7154f0) and raises pending flag 0x6c4fdf consumed by confirm SM. Downstream action type defined elsewhere.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627a80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
