# 0x0060abc0 inflate_reset

| field | value |
|---|---|
| Original address | 0x0060abc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060abc0 |
| Resolved name | inflate_reset |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060acb0, FUN_0060c690
**Callees:** FUN_00608ab0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflateReset: zeroes stream counters (+0x18/+8/+0x20), sets mode to BLOCKS(7) or start(0) by nowrap flag, and calls inflate_blocks_reset.

## Notes / uncertainty
zlib inflateReset. Zeroes total_in/out/msg, mode=nowrap?BLOCKS(7):METHOD(0), then inflate_blocks_reset. total_in/out are 8-byte in this PS2 build.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060abc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
