# 0x0060f8b0 ctxtab_lookup_0x653f70 (per-language object handle)

| field | value |
|---|---|
| Original address | 0x0060f8b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f8b0 |
| Resolved name | ctxtab_lookup_0x653f70 (per-language object handle) |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006130a0, FUN_006139c0, FUN_006140d0
**Callees:** —
**Referenced globals:** 0x653f70 (per-lang ctx table); bRam0034359d (language)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d language

## Behavioral explanation
Returns *(0x653f70 + lang*4): a per-language pointer/handle (name-context object used by roster renderers).

## Notes / uncertainty
Single-level 0x653f70[lang] -> per-language context-object pointer (callers deref +0x28/+0x2c for default-name strings). No second index.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f8b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
