# 0x005e8ba0 tag_speed_zero_a

| field | value |
|---|---|
| Original address | 0x005e8ba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8ba0 |
| Resolved name | tag_speed_zero_a |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040
**Referenced globals:** +0x12 (speed); +0x251e (per-entry speed); +0xd892/+0xd894
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x12; +0x251e

## Behavioral explanation
Markup tag handler: flushes then sets text-speed/delay to 0 (global +0x12 or per-entry +0x251e).

## Notes / uncertainty
Hard-flush then set auto-advance/typewriter delay=0 at +0x12 (main) or +0x251e (per-entry). Delay unit frames (peer sets 0x3c); per-glyph vs page-timer ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8ba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
