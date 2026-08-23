# 0x005ee610 layout_input_field

| field | value |
|---|---|
| Original address | 0x005ee610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee610 |
| Resolved name | layout_input_field |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e8d30, FUN_005e8eb0
**Callees:** FUN_005eced0, FUN_005ed460, FUN_005ee220, FUN_005f2e50
**Referenced globals:** iRam007012a0; +0xd8bc/+0xd8c0 (cursor); +0xdf6 (field width); +0x10 (container); +0x182 (max width); +0x186 (pass)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd892

## Behavioral explanation
Lays out an input field: computes x with center offset, wraps to a new line if it overflows, updates max width on measure pass, then draws via draw_input_field and advances the cursor.

## Notes / uncertainty
Positions input w/ wrap, min-width(+0x182) on pass 0xf6, calls draw_input_field, advances cursor; table-mode delegates FUN_005f2e50. FUN_005eced0 inner-pad + center offsets inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
