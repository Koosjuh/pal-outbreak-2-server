# 0x005df170 url_resolve_relative

| field | value |
|---|---|
| Original address | 0x005df170 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df170 |
| Resolved name | url_resolve_relative |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005df340
**Callees:** FUN_005dee60, FUN_005deea0, FUN_005deee0, FUN_005def30, FUN_005df020, FUN_005df060, FUN_005df780
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Resolves a relative URL against a base: locates the base directory (last '/'), splices the relative path in, ensures trailing slashes and collapses '//'.

## Notes / uncertainty
Rewrote to full reconstruction. Merge block (scheme gate, splice via authority-path/last-slash, memmove+memcpy prefix) is high-confidence; the trailing-slash normalization tail relies on inferred reads of Ghidra register artifacts (extraout_a1_lo/a2/a3/t0_lo) so bounds 0xFE/0xFF and end[-1] reads are best-consistent, not byte-exact -> Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
