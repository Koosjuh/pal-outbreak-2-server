# 0x0061e6e0 ui_gfx_ctx_exit

| field | value |
|---|---|
| Original address | 0x0061e6e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e6e0 |
| Resolved name | ui_gfx_ctx_exit |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_0061d6a0, FUN_0061ded0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Teardown counterpart to e650: gfx primitive 0x1f4630 then 0x1f5630(0).

## Notes / uncertainty
Two-call gfx teardown (ext 0x1f4630 then 0x1f5630(0)); externs opaque so domain meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e6e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
