# 0x005f60d0 playerlist_input

| field | value |
|---|---|
| Original address | 0x005f60d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f60d0 |
| Resolved name | playerlist_input |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f5f80
**Callees:** FUN_005b1190, FUN_005b14b0
**Referenced globals:** 0x70a164/17c(list entry + flags); 0x695d60(registry); pad via FUN_005b14b0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70a17c (entry flags: bit0 toggle, bit7 dirty)

## Behavioral explanation
Player-list cursor/selection input: moves the highlight, toggles a per-entry flag (bit0/0x80) on select, and handles cancel.

## Notes / uncertainty
Player-list pad input: cursor step + confirm toggles entry bit0 and sets dirty bit0x80 (fed to apply_flags), cancel(0x200) returns true. Exact pad-mask->button map inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f60d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
