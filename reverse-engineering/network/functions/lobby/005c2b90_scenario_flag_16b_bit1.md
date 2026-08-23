# 0x005c2b90 scenario_flag_16b_bit1

| field | value |
|---|---|
| Original address | 0x005c2b90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2b90 |
| Resolved name | scenario_flag_16b_bit1 |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c2f40
**Callees:** FUN_005c2a40
**Referenced globals:** iRam00368474 (via scenario_record_ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns bit1 of the flag byte at scenario_record + 0x16b.

## Notes / uncertainty
bit1 of flag byte scenario_record+0x16b; caller stores to uRam006d2295. Companion to bit0 getter. Semantic not validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
