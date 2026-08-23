# 0x001ee770 snap_open_f0bf0_flag0

| field | value |
|---|---|
| Original address | 0x001ee770 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee770 |
| Resolved name | snap_open_f0bf0_flag0 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001f0bf0
**Referenced globals:** 0x37a2a4 (SNAP mode flag=0)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a4

## Behavioral explanation
Opens a SN@P resource via FUN_001f0bf0(), returns handle (or -1), sets mode flag 0x37a2a4=0.

## Notes / uncertainty
Twin of 720: open via 001f0bf0, latch 0x37a2a4=0. Complementary open-path selector; semantic axis undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
