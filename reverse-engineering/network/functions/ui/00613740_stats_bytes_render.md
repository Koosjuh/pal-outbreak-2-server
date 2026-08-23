# 0x00613740 stats_bytes_render

| field | value |
|---|---|
| Original address | 0x00613740 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613740 |
| Resolved name | stats_bytes_render |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_006146e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Formats 4 consecutive bytes as space-padded 'NNN. ' decimal fields into a stack buffer and draws it (FUN_006146e0) at param y.

## Notes / uncertainty
Formats 4 u8 into space-suppressed 'AAA.BBB.CCC.DDD' quartet, draws once. Domain of the 4 bytes (stat quartet vs version) unresolved; not an IP (IP fmt is 0x614550).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613740.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
