# 0x005b2460 init_menu_context

| field | value |
|---|---|
| Original address | 0x005b2460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2460 |
| Resolved name | init_menu_context |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_00632c70
**Referenced globals:** 0x6c4628 menu-context struct base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4628

## Behavioral explanation
Wrapper that initializes the menu-context struct at 0x6c4628 via 0x632c70.

## Notes / uncertainty
Wrapper: context_struct_init(0x6c4628). 0x6c4628 is the menu-context block adjacent to g_softKey 0x6c462a read by the input predicates. Block layout/size not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
