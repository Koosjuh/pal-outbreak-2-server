# 0x005ec8b0 skip_leading_whitespace

| field | value |
|---|---|
| Original address | 0x005ec8b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec8b0 |
| Resolved name | skip_leading_whitespace |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eea60
**Callees:** —
**Referenced globals:** DAT_006491b0 (char class); +0xd8cc/+0x18b (wrap flags)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x18b (nowrap); +0xd8cc

## Behavioral explanation
Advances a text pointer past leading whitespace (char-class &2) unless the pre/no-wrap flags (+0xd8cc/+0x18b) are set.

## Notes / uncertainty
Collapses leading whitespace (charclass DAT_006491b0 bit 2) unless preserve flags +0xd8cc/+0x18b set. Which flag is pre vs nobr inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec8b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
