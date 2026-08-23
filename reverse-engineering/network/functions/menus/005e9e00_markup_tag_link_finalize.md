# 0x005e9e00 markup_tag_link_finalize

| field | value |
|---|---|
| Original address | 0x005e9e00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9e00 |
| Resolved name | markup_tag_link_finalize |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ede30
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper invoking FUN_005ede30 (refresh/rebuild).

## Notes / uncertainty
Trampoline to FUN_005ede30: submit link +0x6f0 (visible pass), no flush/clear. Distinct trigger vs 0x9d50 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9e00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
