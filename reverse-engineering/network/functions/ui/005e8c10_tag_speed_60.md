# 0x005e8c10 tag_speed_60

| field | value |
|---|---|
| Original address | 0x005e8c10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8c10 |
| Resolved name | tag_speed_60 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040, FUN_005ef780
**Referenced globals:** +0x12 / +0x251e (speed); +0xd892/+0xd894
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x12; +0x251e

## Behavioral explanation
Markup tag handler: flushes then sets text-speed/delay to 0x3c (60) (global +0x12 or per-entry +0x251e).

## Notes / uncertainty
Hard-flush, set delay=0x3c(60 frames); per-entry path also recomputes align via FUN_005ef780. Same delay-semantics ambiguity.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
