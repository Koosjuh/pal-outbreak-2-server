# 0x0060acb0 inflate_init2 (inflateInit2_)

| field | value |
|---|---|
| Original address | 0x0060acb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060acb0 |
| Resolved name | inflate_init2 (inflateInit2_) |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060ae20
**Callees:** FUN_00608b70, FUN_0060abc0, FUN_0060ac30, FUN_0060be50, FUN_0060c0f0
**Referenced globals:** 0x0064a260 version-str
**Referenced strings:** 1.1.4
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflateInit2_: validates version '1.1.4' and stream-size 0x48, installs ZALLOC/ZFREE defaults, validates windowBits 8-15 (nowrap if negative), allocs the state + block window, then inflateReset.

## Notes / uncertainty
zlib entry point; version '1.1.4' @0x64a260 + stream_size 0x48 checks FIX the whole cluster as zlib 1.1.4. windowBits 8..15, negative=nowrap, adler32 checkfn 0x0060be50 (named by role). Return codes -6/-2/-4/0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060acb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
