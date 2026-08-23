# 0x00628cc0 render_center_dialog_2line

| field | value |
|---|---|
| Original address | 0x00628cc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628cc0 |
| Resolved name | render_center_dialog_2line |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fea0
**Referenced globals:** 0x66a9c0 str-ids
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Render callback that horizontally centers and draws a two-string prompt (string ids 0x5a/0x5b) at y=0x168, storing the computed x back into the record.

## Notes / uncertainty
Centered 2-string prompt (ids 0x5a/0x5b) at y=0x168, visibility gated on *(ctx)<2. Gating count meaning (single/multiplayer?) and string text unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628cc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
