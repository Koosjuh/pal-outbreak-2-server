# 0x005e91f0 tag_apply_if_name_matches_1528

| field | value |
|---|---|
| Original address | 0x005e91f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e91f0 |
| Resolved name | tag_apply_if_name_matches_1528 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ee470
**Referenced globals:** +0x1528 (16-byte field); 0x648370 (remap table); 0x648510 (reference string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1528

## Behavioral explanation
Markup tag handler: remaps the 16-byte +0x1528 field through table 0x648370 and, if it equals reference string 0x648510, invokes FUN_005ee470 (keyword/cheat match action).

## Notes / uncertainty
Case-folds 16B name via DAT_00648370, strcmp vs ref keyword 0x648510; on match calls FUN_005ee470 (anchor draw). Match->draw flow certain; literal keyword text at 0x648510 not resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e91f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
