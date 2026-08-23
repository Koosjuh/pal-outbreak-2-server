# 0x00608ab0 inflate_blocks_reset

| field | value |
|---|---|
| Original address | 0x00608ab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608ab0 |
| Resolved name | inflate_blocks_reset |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00608b70, FUN_00609b70, FUN_0060abc0, FUN_0060ae40
**Callees:** FUN_0060a650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflate_blocks_reset: on active code tree (type 6) frees it, zeroes block-decoder state (+0x1c..+0x27), resets window read/write ptrs and re-inits the check callback at +0x3c.

## Notes / uncertainty
zlib 1.1.4. Frees blens(mode4/5)/codes(mode6), zeroes bitk/bitb, resets read/write to window, seeds check. Mode enum documented. Static ID, no runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
