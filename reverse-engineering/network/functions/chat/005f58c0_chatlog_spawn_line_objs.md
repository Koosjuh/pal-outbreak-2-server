# 0x005f58c0 chatlog_spawn_line_objs

| field | value |
|---|---|
| Original address | 0x005f58c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f58c0 |
| Resolved name | chatlog_spawn_line_objs |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006020e0
**Callees:** FUN_00618ba0
**Referenced globals:** 0x6c54d0(per-row visible cache)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates N (5/10/11) display-list nodes for chat rows, each with per-line callback FUN_005f5970.

## Notes / uncertainty
Allocates one display-node per row (11/5/10 by mode) via FUN_00618ba0; stamps node[0]=1,[2]=mode,[3]=row and installs callback FUN_005f5970 at node+0xc. Breaks on alloc failure (partial spawn). Full node struct beyond touched fields unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f58c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
