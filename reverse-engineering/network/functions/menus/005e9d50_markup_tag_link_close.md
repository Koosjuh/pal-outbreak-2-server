# 0x005e9d50 markup_tag_link_close

| field | value |
|---|---|
| Original address | 0x005e9d50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9d50 |
| Resolved name | markup_tag_link_close |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ede30, FUN_005eef70
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x6f0 (0x101 buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Applies arg, zeroes 0x101-byte buf at cfg+0x6f0, then FUN_005ede30 (refresh/rebuild).

## Notes / uncertainty
Flush run, clear +0x6f0 link buffer (0x101), finalize link via FUN_005ede30 (submits +0x6f0 when visible pass). FUN_005d9290 = link-register (undecoded).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9d50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
