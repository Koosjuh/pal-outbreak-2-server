# 0x001c00f0 set_boot_state

| field | value |
|---|---|
| Original address | 0x001c00f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c00f0 |
| Resolved name | set_boot_state |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0020
**Callees:** —
**Referenced globals:** 0x35a6b0 boot-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35a6b0

## Behavioral explanation
Trivial setter for the DNAS boot-state var 0x35a6b0.

## Notes / uncertainty
Setter for boot-state 0x35a6b0 (domain 0..5 from FUN_001c0100 switch). Initial value at dnas_boot_init call site (0) inferred from ABI.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c00f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
