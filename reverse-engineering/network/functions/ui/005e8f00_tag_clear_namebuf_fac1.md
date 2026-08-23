# 0x005e8f00 tag_clear_namebuf_fac1

| field | value |
|---|---|
| Original address | 0x005e8f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8f00 |
| Resolved name | tag_clear_namebuf_fac1 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** +0xfac1 (string field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: zeroes the 0x100-byte render-ctx field at +0xfac1.

## Notes / uncertainty
memset(ctx+0xfac1,0,0x100). +0xfac1 = current anchor/link target name buffer (strcmp key in FUN_005ee470 vs +0xea81 record array). Field semantics inferred from single consumer; clear itself certain. Not network.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8f00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
