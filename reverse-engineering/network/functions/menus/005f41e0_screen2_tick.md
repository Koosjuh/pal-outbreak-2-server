# 0x005f41e0 screen2_tick

| field | value |
|---|---|
| Original address | 0x005f41e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f41e0 |
| Resolved name | screen2_tick |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3ff0
**Callees:** FUN_00621f10, FUN_0062ff30, FUN_00637970
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Per-frame draw/update for the second scene object.

## Notes / uncertainty
Second-screen per-frame draw trio only (no counter/timed events). Identical to 005f3f50's unconditional tail.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f41e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
