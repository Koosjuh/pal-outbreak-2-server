# 0x005e9790 textbuf_flush_if_pending_0x7f0

| field | value |
|---|---|
| Original address | 0x005e9790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9790 |
| Resolved name | textbuf_flush_if_pending_0x7f0 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e97d0, FUN_005e9840, FUN_005e9e20
**Callees:** FUN_005ede80
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x7f0 (alloc flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0

## Behavioral explanation
If flag cfg+0x7f0 set, frees the associated list/buffer (FUN_005ede80) and clears the flag.

## Notes / uncertainty
Shared flush: if cfg+0x7f0 open flag set, commit via FUN_005ede80 (trim+width+copy into cfg+0x7f1) and clear. No-arg ede80 call (dropped arg) is only fuzz.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
