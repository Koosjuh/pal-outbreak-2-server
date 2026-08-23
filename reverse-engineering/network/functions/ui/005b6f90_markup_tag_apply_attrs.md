# 0x005b6f90 markup_tag_apply_attrs

| field | value |
|---|---|
| Original address | 0x005b6f90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6f90 |
| Resolved name | markup_tag_apply_attrs |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b7270
**Callees:** —
**Referenced globals:** 0x638f20 (PTR_s_DUMMY tag keyword table); 0x6ca2e0 (tag buffer); uRam006ca880/882 (attr state)
**Referenced strings:** DUMMY (via PTR_s_DUMMY_00638f20)
**Referenced opcodes:** —
**State vars:** uRam006ca880; uRam006ca882

## Behavioral explanation
Match the current tag token against 11 known keywords (PTR table 0x638f20) and set attribute bits/params (color/hex nibble, alignment, etc.) on the render-state struct param_1.

## Notes / uncertainty
11-keyword strcmp match -> flag bits 0x001..0x100 + hex/dec nibble parse into attr slots; 0x188 = terminating set. Per-tag semantics inferred; keyword strings (except DUMMY) not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6f90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
