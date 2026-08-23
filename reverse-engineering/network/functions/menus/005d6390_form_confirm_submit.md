# 0x005d6390 form_confirm_submit

| field | value |
|---|---|
| Original address | 0x005d6390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6390 |
| Resolved name | form_confirm_submit |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005cc980
**Callees:** FUN_005d5900, FUN_005d59f0, FUN_005d5a40, FUN_005d5cc0
**Referenced globals:** 0x701068+0x60dcb flag; 0x701068+0x4f7a0 str; 0x701068+0x60dcc counter; 0x8710fc cmp str
**Referenced strings:** str@0x8710fc
**Referenced opcodes:** —
**State vars:** 0x701068+0x60dcb

## Behavioral explanation
Confirm handler gated on 0x60dcb: sets label from 0x4f7a0, compares to a stored string, then runs the name-submit compose (5900).

## Notes / uncertainty
Confirm-dialog handler gated on confirm_enable(+0x60dcb)==1, one-shot via reentry_guard +0x60dcc; if confirm text == 0x8710fc runs name/pw compose (5900)+return-list, else reset (59f0); returns 2 handled/0 idle. String 0x8710fc semantics unclear; strcmp inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6390.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
