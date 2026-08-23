# 0x005e98e0 textbuf_end_commit_0x7f0

| field | value |
|---|---|
| Original address | 0x005e98e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e98e0 |
| Resolved name | textbuf_end_commit_0x7f0 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ede80
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x7f0 (flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0

## Behavioral explanation
Finalizes/frees the 0x7f0 buffer (FUN_005ede80(arg)) and clears flag cfg+0x7f0.

## Notes / uncertainty
End block: FUN_005ede80(param_2) trim/commit then clear cfg+0x7f0. Whether param_2 == cfg+0x7f1 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e98e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
