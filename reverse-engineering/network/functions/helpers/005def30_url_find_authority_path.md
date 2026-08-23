# 0x005def30 url_find_authority_path

| field | value |
|---|---|
| Original address | 0x005def30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005def30 |
| Resolved name | url_find_authority_path |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df170, FUN_005df340
**Callees:** FUN_005df780
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Given a URL, uses scheme detection (FUN_005df780) to skip a 6-char scheme or the '//' authority, returning the start of the path.

## Notes / uncertainty
Rewrote to full reconstruction. Returns path start: scheme class 1 -> url+6 fixed prefix, class 0 -> NULL, class>=2 -> skip '//authority' then first path '/'. Uncertainty: the concrete class-1 6-byte scheme string (table at 0x646570) is unrecovered.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005def30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
