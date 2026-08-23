# 0x005e9e20 markup_tag_linebreak

| field | value |
|---|---|
| Original address | 0x005e9e20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9e20 |
| Resolved name | markup_tag_linebreak |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e9790, FUN_005ee010
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x7f0 (buffer flag); cfg+0x4 (counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0; cfg+0x4

## Behavioral explanation
Frees 0x7f0 buffer (FUN_005e9790), runs FUN_005ee010, resets counter cfg+4=0 and *arg=0.

## Notes / uncertainty
Line-break: close inline object (FUN_005e9790 via +0x7f0), advance layout row (FUN_005ee010), reset run +0x4 and *cursor. Inline-object type undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9e20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
