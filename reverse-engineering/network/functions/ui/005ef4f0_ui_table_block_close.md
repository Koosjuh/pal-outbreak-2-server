# 0x005ef4f0 ui_table_block_close

| field | value |
|---|---|
| Original address | 0x005ef4f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef4f0 |
| Resolved name | ui_table_block_close |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8510
**Callees:** FUN_005d8b00
**Referenced globals:** +0x186 render-pass mode; +0xe96b draw-suppress; +0x4 active-op field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b

## Behavioral explanation
Close/finalize helper: in draw mode calls draw-region teardown 0x5d8b00, then clears ctx+0x4 active-op and caller's active flag.

## Notes / uncertainty
Close counterpart to ui_table_state_reset: draw_region_end in draw pass, then clear ctx+0x4 and caller flag. Renamed from ui_dialog_close_simple (draw-region pairing points to table/block close).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef4f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
