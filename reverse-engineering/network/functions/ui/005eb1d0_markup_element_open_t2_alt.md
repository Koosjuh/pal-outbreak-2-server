# 0x005eb1d0 markup_element_open_t2_alt

| field | value |
|---|---|
| Original address | 0x005eb1d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb1d0 |
| Resolved name | markup_element_open_t2_alt |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eb250, FUN_005ef5b0, FUN_005ef850, FUN_005f0e10
**Referenced globals:** +4; +0x186
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Type-2 element open variant: begins element (FUN_005f0e10 arg 2), layout+commit, then unconditionally calls layout helper FUN_005eb250.

## Notes / uncertainty
Kind-2 open variant; calls FUN_005eb250 unconditionally (helper does pass-mode gate internally). Reason for two variants unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb1d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
