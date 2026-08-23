# 0x005df020 url_find_first_slash

| field | value |
|---|---|
| Original address | 0x005df020 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df020 |
| Resolved name | url_find_first_slash |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df170
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans forward within [param_1,param_2) for the first '/' and returns it (or NULL).

## Notes / uncertainty
Rewrote to full reconstruction. First '/' in [start,end) else NULL. Control flow unambiguous (pcVar1 pre-clear idiom preserved).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
