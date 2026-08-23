# 0x00608b70 inflate_blocks_new

| field | value |
|---|---|
| Original address | 0x00608b70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608b70 |
| Resolved name | inflate_blocks_new |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060acb0
**Callees:** FUN_00608ab0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflate_blocks_new: allocates the 0x48 block-state struct + a window (via ZALLOC callbacks), stores checkfn at +0x3c, and calls inflate_blocks_reset.

## Notes / uncertainty
zlib. Allocs 0x48 state + hufts(MANY=0x5a0) + window(w), rollback on OOM, then reset. Sizes match zlib 1.1.4.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
