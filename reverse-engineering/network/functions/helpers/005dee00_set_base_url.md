# 0x005dee00 set_base_url

| field | value |
|---|---|
| Original address | 0x005dee00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dee00 |
| Resolved name | set_base_url |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d8aa0
**Callees:** FUN_005dedc0, FUN_005dee40
**Referenced globals:** iRam00701068+0x4cf5c (base URL buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x4cf5c

## Behavioral explanation
Copies a URL string into the browser context base-URL slot (+0x4cf5c) via strlcpy_255 after an (unresolvable) prologue stub.

## Notes / uncertainty
Already reconstructed: installs base URL into iRam00701068+0x4cf5c (the field read by url_canonicalize) via strncpy_255. Medium only because prologue FUN_005dee40 is a halt_baddata stub. Left untouched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dee00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
