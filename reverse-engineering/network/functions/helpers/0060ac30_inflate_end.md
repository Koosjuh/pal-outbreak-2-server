# 0x0060ac30 inflate_end

| field | value |
|---|---|
| Original address | 0x0060ac30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060ac30 |
| Resolved name | inflate_end |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060acb0, FUN_0060d4f0
**Callees:** FUN_00609b70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflateEnd: frees the block-state (inflate_blocks_free) then ZFREEs the internal state struct (+0x24).

## Notes / uncertainty
zlib inflateEnd. inflate_blocks_free then ZFREE state, null z->state. Z_OK/Z_STREAM_ERROR.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060ac30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
