# 0x005e97d0 textbuf_begin_reset_0x7f1

| field | value |
|---|---|
| Original address | 0x005e97d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e97d0 |
| Resolved name | textbuf_begin_reset_0x7f1 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e9790
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x7f0 (flag); cfg+0x7f1 (0x101 buf); cfg+0x4 (counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0; cfg+0x4

## Behavioral explanation
Frees prior buffer, sets flag 0x7f0=1, zeroes 0x101-byte buf at cfg+0x7f1, resets counter cfg+4=0 and *arg=0.

## Notes / uncertainty
Begin text block WITH counter reset: flush prior, flag=1, memset 0x101 buf, cfg+4=0, *param_2=0. cfg+4 role (line idx vs offset) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e97d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
