# 0x00618e30 sprite_draw_entry

| field | value |
|---|---|
| Original address | 0x00618e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618e30 |
| Resolved name | sprite_draw_entry |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00618c90, FUN_00619220
**Callees:** FUN_00637f90, FUN_006381e0
**Referenced globals:** PTR_DAT_0066fdd0 part-table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Renders one sprite/actor: walks its part list (PTR_DAT_0066fdd0-indexed), resolves per-part flags (flip 0x4000/0x8000, override 0x200/0x400, text 0x1000), sets UV/color and emits quads or text runs.

## Notes / uncertainty
Walks sprite part-list (PTR_DAT_0066fdd0[+0x22], 0x14 stride, part[0]==0 term). Full flag table decoded: 0x2000 blend,0x1000 text,0x800 direct-vs-CLUT,0x400/0x200 override geometry (part^obj flags),0x8000/0x4000 flip,0x100 packed color,0x80 raw color. Control flow certain; GS/color byte-order inferred. NOTE: these are GS attr bits, NOT SN@P who-byte.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
