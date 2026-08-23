# 0x001eaddc attr_table_byteswap_hton

| field | value |
|---|---|
| Original address | 0x001eaddc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eaddc |
| Resolved name | attr_table_byteswap_hton |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6ee0, FUN_001db7e8
**Callees:** FUN_001069a8, FUN_001e2304, FUN_001e234c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps an attribute table in place: swaps the u16 count and each entry's u16 key (FUN_001e234c) and u32 value (FUN_001e2304) — network/host order conversion.

## Notes / uncertainty
In-place TLV byteswap; count sampled PRE-swap => hton (serialize) direction. hton/ntoh label inferred from count-sampling order + mirror; swap is byte-identical on LE.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eaddc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
