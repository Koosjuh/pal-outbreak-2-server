# 0x005e9360 commit_run_ef3f0

| field | value |
|---|---|
| Original address | 0x005e9360 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9360 |
| Resolved name | commit_run_ef3f0 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e9270
**Callees:** FUN_005ef3f0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper that invokes apply/refresh routine FUN_005ef3f0.

## Notes / uncertainty
Pure trampoline to FUN_005ef3f0 (glyph-run commit+conditional draw, gated on +0x186/+0xe96b). Upgraded Medium->High; wrapper fully certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
