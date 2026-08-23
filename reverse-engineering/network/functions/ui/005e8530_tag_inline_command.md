# 0x005e8530 tag_inline_command

| field | value |
|---|---|
| Original address | 0x005e8530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8530 |
| Resolved name | tag_inline_command |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d8aa0, FUN_005ec1b0
**Referenced globals:** iRam007012a0+0x186 (measure-only); +0xe96b (silent)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b

## Behavioral explanation
Markup tag handler: extracts a 256-byte string arg and, unless in measure/silent mode, dispatches it as a command (FUN_005d8aa0), likely sound/effect.

## Notes / uncertainty
Extracts ="..." arg via FUN_005ec1b0, dispatches to FUN_005d8aa0 only when not measure(+0x186)/silent(+0xe96b). Command target (sound/effect/script) inferred; d8aa0 not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
