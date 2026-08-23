# 0x00609c60 inflate_codes

| field | value |
|---|---|
| Original address | 0x00609c60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00609c60 |
| Resolved name | inflate_codes |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00608c80
**Callees:** FUN_0060a670, FUN_0060bca0
**Referenced globals:** 0x0064b530 bit-mask-table
**Referenced strings:** invalid literal/length code; invalid distance code
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflate_codes: the literal/length/distance Huffman decode state machine copying into the sliding window, with error exits via FUN_0060bca0.

## Notes / uncertainty
zlib per-block literal/length/distance decode coroutine (modes START..BADCODE), delegates hot path to inflate_fast. COPY/LIT window-full sub-branches reproduced structurally. No runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00609c60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
