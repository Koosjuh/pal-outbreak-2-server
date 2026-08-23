# 0x005f2450 ui_layout_hr_advance

| field | value |
|---|---|
| Original address | 0x005f2450 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2450 |
| Resolved name | ui_layout_hr_advance |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed1f0
**Callees:** FUN_005d93f0, FUN_005ec170, FUN_005ed160, FUN_005ef780
**Referenced globals:** +0x186 pass; +0x188 root idx; +0x8f2/+0x8f4 line metrics; +0xd8ce..+0xd8dc layout cursors; +0x1540 root array
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8d0; +0xd8d4

## Behavioral explanation
Advances the layout cursor to a new line/row: bumps vertical cursors (+0xd8d0), in draw mode emits a horizontal rule via 0x5d93f0, and updates content-width/root extents.

## Notes / uncertainty
Renamed from newline_advance: emits an HR/block separator (5d93f0) and advances vertical cursor; default width 0x248 in arrange pass, records hit-rect. Cursor semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f2450.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
