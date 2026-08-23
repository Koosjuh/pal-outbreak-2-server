# 0x005bb270 draw_message_line

| field | value |
|---|---|
| Original address | 0x005bb270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb270 |
| Resolved name | draw_message_line |
| Subsystem | chat |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bb380
**Callees:** —
**Referenced globals:** 0x639e50 delimiter/token; 0x639d58 prefix string; 0x639e58/0x639e60 separators; 0x0034359d cRam=region/format flag
**Referenced strings:** 0x639d58; 0x639e50; 0x639e58; 0x639e60
**Referenced opcodes:** —
**State vars:** cRam0034359d

## Behavioral explanation
Formats and draws one message/chat line: copies the string, splits on the '%s'-style token at 0x639e50, prepends a prefix (0x639d58, region-adjusted by cRam0034359d) then draws via func_0x001b7310.

## Notes / uncertainty
Single-line template renderer: strcpy line, split on 2-byte token 0x639e50, insert region-adjusted prefix 0x639d58 (width-convert if 0x34359d==0) wrapped by seps e58/e60, draw via func_0x001b7310. Token/prefix text unresolved (str@ only).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
