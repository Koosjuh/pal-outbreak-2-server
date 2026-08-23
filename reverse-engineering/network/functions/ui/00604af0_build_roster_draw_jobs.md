# 0x00604af0 build_roster_draw_jobs

| field | value |
|---|---|
| Original address | 0x00604af0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604af0 |
| Resolved name | build_roster_draw_jobs |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00603f30
**Callees:** FUN_005b7fd0, FUN_005ba570, FUN_005ba7b0, FUN_00618ba0
**Referenced globals:** &DAT_00649ff0 (row x-coord table); ctx+0x905 (row count); ctx+0x909
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x905

## Behavioral explanation
Allocates a chain of UI draw nodes (ids 0x6b/0x6c/0x6d/0x6e, up to 7 member rows) via FUN_00618ba0, wiring row callbacks FUN_006050d0 and header/footer callbacks FUN_00604e70, then queues them (005ba570/005ba7b0).

## Notes / uncertainty
Builds in-room roster panel: header 0x6b, 2 nodes/member (0x6c bg + 0x64 content, clamp 7) driven by member count 0x6c5495, footers 0x6d/0x6e. Direct tie to create-room symptom: count=0 => zero member rows. Row-content cb FUN_006050d0 (draws name/id) not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604af0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
