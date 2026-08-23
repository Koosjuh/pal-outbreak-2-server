# 0x005ef040 render_text_token_inline

| field | value |
|---|---|
| Original address | 0x005ef040 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef040 |
| Resolved name | render_text_token_inline |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7a30, FUN_005e84b0, FUN_005e84d0, FUN_005e88c0, FUN_005e8960, FUN_005e8990, FUN_005e89f0, FUN_005e8ad0, FUN_005e8b40, FUN_005e8ba0, FUN_005e8c10, FUN_005e9ff0, FUN_005ea090
**Callees:** FUN_005ec170, FUN_005eea60, FUN_005eeca0, FUN_005eed40, FUN_005f3bc0
**Referenced globals:** iRam007012a0; +0x4 (buf len); +0xd8bc (cursor); +0xd892 (depth); +0x188 (line idx)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892

## Behavioral explanation
Inline variant of render_text_token: layout_text_run + flush_text_buffer + finalize_run_metrics (keeps run on the same line rather than forcing a break); block-stack branch delegates to FUN_005f3bc0.

## Notes / uncertainty
Inline variant of render_text_token: uses finalize_run_metrics (0x5eed40) for same-line advance instead of cursor reset; delegates 0x5f3bc0. Exact metric in 0x5eed40 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef040.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
