# 0x005deee0 url_find_extension_dot

| field | value |
|---|---|
| Original address | 0x005deee0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005deee0 |
| Resolved name | url_find_extension_dot |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df170, FUN_005df7b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans backward for a '.' before hitting a '/', returning the extension dot pointer or NULL.

## Notes / uncertainty
Already complete: reverse scan for extension '.' within the final segment; bails NULL on '/' or reaching start. Drives directory trailing-slash decision. Left untouched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005deee0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
