# 0x0062b620 copy_tag_until_gt

| field | value |
|---|---|
| Original address | 0x0062b620 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062b620 |
| Resolved name | copy_tag_until_gt |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062b500
**Callees:** —
**Referenced globals:** 0x715480 token buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies characters into the 0x715480 token buffer up to and including '>' and returns the advanced source pointer.

## Notes / uncertainty
Tiny scanner: copies bytes into scratch 0x715480 up to and including '>', returns src past '>'. Caller memsets buffer (provides terminator). Fully understood; only unbounded-input assumption noted.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062b620.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
