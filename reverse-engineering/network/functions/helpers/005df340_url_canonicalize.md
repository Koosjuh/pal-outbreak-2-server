# 0x005df340 url_canonicalize

| field | value |
|---|---|
| Original address | 0x005df340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df340 |
| Resolved name | url_canonicalize |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d7e00, FUN_005d7f80
**Callees:** FUN_005dee60, FUN_005deea0, FUN_005def30, FUN_005df060, FUN_005df0b0, FUN_005df110, FUN_005df170, FUN_005df640, FUN_005df780
**Referenced globals:** iRam00701068+0x4cf5c (base URL); 0x6465a8 (default/empty URL); 0x6465b8 (segment literal)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x4cf5c

## Behavioral explanation
Full URL canonicalizer: rejects javascript: (FUN_005df640), resolves against the context base URL (+0x4cf5c), then collapses '//','/./','/../' segments into a normalized absolute URL.

## Notes / uncertainty
Rewrote to full reconstruction. javascript:-blocklist gate (FUN_005df640==-1) -> resolve twice vs context base (iRam+0x4cf5c) -> //, /../ (authority vs non-authority split), /./ collapse loops. remove_dot_segments structure high-confidence; Medium due to param_2 buffer aliasing between blocklist gate and second resolve, and inferred '/..' literal at 0x6465b8.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
