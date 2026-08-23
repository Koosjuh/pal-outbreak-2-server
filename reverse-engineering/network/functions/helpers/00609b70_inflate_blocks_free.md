# 0x00609b70 inflate_blocks_free

| field | value |
|---|---|
| Original address | 0x00609b70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00609b70 |
| Resolved name | inflate_blocks_free |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060ac30
**Callees:** FUN_00608ab0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflate_blocks_free: resets block state then ZFREEs the window (+0x2c), decoder (+0x28) and the block-state struct itself.

## Notes / uncertainty
zlib. reset then ZFREE window/hufts/state. Returns Z_OK. Unambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00609b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
