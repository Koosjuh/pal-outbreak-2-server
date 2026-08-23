# 0x005e83c0 textmarkup_ctx_reset

| field | value |
|---|---|
| Original address | 0x005e83c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e83c0 |
| Resolved name | textmarkup_ctx_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** iRam007012a0 (render ctx); 0x648500/0x648508 (default strings)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4 (out len); +0x1c; +0xd8bc..+0xd8cc (coord/state counters)

## Behavioral explanation
Initializes the text-render context: zeroes out-length, cursor/coord counters, and copies two default strings into ctx+0x2a3/+0x2b3.

## Notes / uncertainty
Render-ctx initializer: zeroes pen/run state, strcpy 2 default attr strings (0x648500/0x648508). Contents of default strings and +0x1c/+0xd8cc semantics unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e83c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
