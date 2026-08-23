# 0x001ef100 snap_call_f09f0_pair

| field | value |
|---|---|
| Original address | 0x001ef100 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef100 |
| Resolved name | snap_call_f09f0_pair |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001f09f0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wrapper passing a struct base and base+4 (two adjacent fields) plus a scratch out-byte to FUN_001f09f0.

## Notes / uncertainty
splits caller struct into (base,base+4)+out-byte for undecompiled f09f0; field widths (u32) inferred from +4 stride.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef100.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
