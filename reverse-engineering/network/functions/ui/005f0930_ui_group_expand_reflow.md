# 0x005f0930 ui_group_expand_reflow

| field | value |
|---|---|
| Original address | 0x005f0930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0930 |
| Resolved name | ui_group_expand_reflow |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f10a0
**Callees:** FUN_005ef5e0, FUN_005ef850, FUN_005f00b0, FUN_005f0480, FUN_005f08c0
**Referenced globals:** +0xd894 current node; +0x24e0 pool; +0x18d dirty flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x18d

## Behavioral explanation
For each matching group member, allocates a node, inherits attrs and reflows it, looping until no more members — expands a spanned group during layout.

## Notes / uncertainty
Per-member group expansion loop: push scope + alloc(kind4) + inherit + reflow until no more members; sets ctx+0x18d. ef5e0/ef850 internals not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
