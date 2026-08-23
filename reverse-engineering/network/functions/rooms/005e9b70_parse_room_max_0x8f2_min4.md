# 0x005e9b70 parse_room_max_0x8f2_min4

| field | value |
|---|---|
| Original address | 0x005e9b70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9b70 |
| Resolved name | parse_room_max_0x8f2_min4 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x8f2 (max players, min 4)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x8f2

## Behavioral explanation
Parses decimal into cfg+0x8f2 (max players); clamps minimum to 4.

## Notes / uncertainty
Markup attr handler: parse value -> cfg+0x8f2 max players, clamp min 4. Parse base (FUN_005ec650 decimal?) unconfirmed but clamp semantics fixed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
