# 0x005d5640 form_field_submit_compose

| field | value |
|---|---|
| Original address | 0x005d5640 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5640 |
| Resolved name | form_field_submit_compose |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c9c50, FUN_005d6460
**Callees:** FUN_005d5a40, FUN_005d5b60, FUN_005d5cc0, FUN_005d74a0, FUN_005d7540, FUN_005d7690
**Referenced globals:** 0x701070+0x30 sub-state; 0x701080 form buffer; 0x701070+0x55d name; 0x701068+0x60dcd counter
**Referenced strings:** str@0x642fc0; str@0x642c20 field-key; str@0x642c28 field-key
**Referenced opcodes:** —
**State vars:** 0x701070+0x30

## Behavioral explanation
Switch on menu sub-state (0x30) that appends form fields (name/password from 0x701080) via 7540 and transitions the menu; validates entered text.

## Notes / uncertainty
Terminal create/edit form compose: substate switch appends name/password fields (saved-name preferred), validates 2-byte code, commits label+text sink, returns to list. Feeds register/create payload but does not touch wire. Uncertainty: func_0x10a338 (2-byte strncmp vs set) — case-5 discards result; field keys 0x642c20/28 assumed name/password. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5640.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
