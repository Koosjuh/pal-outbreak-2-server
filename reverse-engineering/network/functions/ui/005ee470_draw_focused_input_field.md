# 0x005ee470 draw_focused_input_field

| field | value |
|---|---|
| Original address | 0x005ee470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee470 |
| Resolved name | draw_focused_input_field |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e91f0
**Callees:** FUN_005d9790, FUN_005ed630
**Referenced globals:** iRam007012a0; +0xea80 (field records); +0xfac1 (match key); +0x1538..+0x153e (offsets)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b

## Behavioral explanation
Iterates the registered input-field records (up to 16 at +0xea80, matched by key +0xfac1) and redraws each via FUN_005d9790 with its stored rect.

## Notes / uncertainty
Renamed from draw_registered_input_fields: scans 16 records matching id +0xfac1, draws the ONE match (returns) with attr|0x80 focus bit + viewport offsets +0x1538. Focus-vs-all-fields inferred from early return.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
