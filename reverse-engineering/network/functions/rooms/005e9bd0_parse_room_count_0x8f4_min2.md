# 0x005e9bd0 parse_room_count_0x8f4_min2

| field | value |
|---|---|
| Original address | 0x005e9bd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9bd0 |
| Resolved name | parse_room_count_0x8f4_min2 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec6d0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x8f4 (count/min, min 2)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x8f4

## Behavioral explanation
Parses number (FUN_005ec6d0) into cfg+0x8f4; clamps minimum to 2.

## Notes / uncertainty
Markup attr handler: parse -> cfg+0x8f4 count, clamp min 2. Confirms the live 1/0P count does NOT come through this markup path (floored at 2) — it comes from the reset default (0) or the op-reply path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9bd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
