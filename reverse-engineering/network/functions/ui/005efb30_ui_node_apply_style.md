# 0x005efb30 ui_node_apply_style

| field | value |
|---|---|
| Original address | 0x005efb30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005efb30 |
| Resolved name | ui_node_apply_style |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ea900
**Callees:** —
**Referenced globals:** +0xdfc border; +0xdfe/+0xe00 min size; +0xe02/+0xe04 size; node+0x1c/+0x1e/+0x20/+0x26 geometry; node+0x45 border; node+0x46 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186 build mode (-10)

## Behavioral explanation
In build mode copies style/attr block (ctx+0xdfc/+0xe00/+0xe02/+0xe04) into a node: border, min-size, align flag bits, and derived min width.

## Notes / uncertainty
Build-pass stamp of pending style block (border/min/size at ctx+0xdfc..+0xe04) onto node; sets +0x46 flag bits, width floor. +0x32 role in floor (min_h vs pad) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005efb30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
