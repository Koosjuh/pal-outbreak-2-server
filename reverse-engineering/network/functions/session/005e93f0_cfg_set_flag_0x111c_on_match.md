# 0x005e93f0 cfg_set_flag_0x111c_on_match

| field | value |
|---|---|
| Original address | 0x005e93f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e93f0 |
| Resolved name | cfg_set_flag_0x111c_on_match |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec320
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x111c (bool flag)
**Referenced strings:** 0x648518 (4-byte cmp const)
**Referenced opcodes:** —
**State vars:** cfg+0x111c

## Behavioral explanation
Extracts token, compares first 4 bytes to const @0x648518; on match sets flag cfg+0x111c=1.

## Notes / uncertainty
Keyword->bool: memcmp(token,@0x648518,4)==0 sets cfg+0x111c=1 (gates the 0x101c apply). Literal 4-byte keyword bytes at 0x648518 not captured in the corpus (need a data dump).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e93f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
