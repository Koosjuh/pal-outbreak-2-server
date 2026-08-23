# 0x001ee720 snap_open_f0b40_flag1

| field | value |
|---|---|
| Original address | 0x001ee720 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee720 |
| Resolved name | snap_open_f0b40_flag1 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0b20
**Callees:** FUN_001f0b40
**Referenced globals:** 0x37a2a4 (SNAP mode flag=1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a4

## Behavioral explanation
Opens a SN@P resource via FUN_001f0b40(), returns handle (or -1), and sets mode flag 0x37a2a4=1.

## Notes / uncertainty
Open via 001f0b40 pass-through, latch mode 0x37a2a4=1 (twin of 001ee770 which sets 0). Flag set even on failure. Mode axis meaning unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
