# 0x005f5970 chatlog_line_obj_cb

| field | value |
|---|---|
| Original address | 0x005f5970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5970 |
| Resolved name | chatlog_line_obj_cb |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af810
**Referenced globals:** 0x6c54d0/54e0(row cache set by chatlog_render)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Per-line display-node callback: positions/sizes a chat row from the cached row metrics, or hides it.

## Notes / uncertainty
Per-row node update callback: hides row if cache 0x6c54d0[row]==0 or sprite alloc (FUN_005af810) fails; else visible + geometry node+0x28=Y(0x54/0x60+row*0x14), node+0x26=cacheX+4, node+0x22=attr+99(sprite id). Field X/Y/id assignment inferred from magnitudes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
