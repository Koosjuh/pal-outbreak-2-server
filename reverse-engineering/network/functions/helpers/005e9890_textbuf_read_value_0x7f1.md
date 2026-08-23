# 0x005e9890 textbuf_read_value_0x7f1

| field | value |
|---|---|
| Original address | 0x005e9890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9890 |
| Resolved name | textbuf_read_value_0x7f1 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x7f1 (0x100 buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x100-byte string into the 0x7f1 accumulation buffer.

## Notes / uncertainty
Body-line handler: cfg_read_value into cfg+0x7f1 (0x101 accumulation buf). Overwrite-vs-append semantics depend on block flag state.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
