# 0x005e9840 textbuf_begin_0x7f1

| field | value |
|---|---|
| Original address | 0x005e9840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9840 |
| Resolved name | textbuf_begin_0x7f1 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e9790
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x7f0 (flag); cfg+0x7f1 (0x101 buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0

## Behavioral explanation
Frees prior buffer, sets flag 0x7f0=1, zeroes 0x101-byte buf at cfg+0x7f1 (no counter reset).

## Notes / uncertainty
Begin variant WITHOUT cfg+4/param_2 reset. Why two variants (which keywords) unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
