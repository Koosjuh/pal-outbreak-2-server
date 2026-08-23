# 0x005d5900 form_name_submit_compose

| field | value |
|---|---|
| Original address | 0x005d5900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5900 |
| Resolved name | form_name_submit_compose |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d6390
**Callees:** FUN_005d74a0, FUN_005d7540
**Referenced globals:** 0x701070+0x55d name; 0x701080 form buffer; 0x701070+0x34 submit flag; 0x700fe8
**Referenced strings:** str@0x642c20; str@0x642c28
**Referenced opcodes:** —
**State vars:** 0x701070+0x34

## Behavioral explanation
Appends name field(s) (0x642c20/0x642c28) from 0x701080 into the form buffer via 7540 and marks submit state.

## Notes / uncertainty
Unconditional name+password compose used by confirm handler; latches submit_done +0x34. Same [inferred] libc thunks as 5640. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
