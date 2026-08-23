# 0x005f5c10 text_censor_entry

| field | value |
|---|---|
| Original address | 0x005f5c10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5c10 |
| Resolved name | text_censor_entry |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b45f0
**Callees:** FUN_005f5a40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Censor entry point: short-circuits on a special 0x81 0x40 prefix, otherwise runs the banned-word filter.

## Notes / uncertainty
Censor wrapper: if string starts with SJIS full-width space 0x81 0x40 route to func_0x00106b60 (bypass), else run text_censor_filter. What 0x00106b60 does with the prefixed line (command parser vs pre-formatted system line) undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
