# 0x001cf570 prepare_area_member_update_aux

| field | value |
|---|---|
| Original address | 0x001cf570 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf570 |
| Resolved name | prepare_area_member_update_aux |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cf3e0
**Callees:** FUN_001a7b70, FUN_001ab460
**Referenced globals:** 0x3bfcec enable table; 0x4288f0 per-index flag/buffer; conn+3 index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Secondary send setup guarded by table 0x3bfcec[area]: sets attribute preset, marks flag at 0x4288f0 and allocates a 0x20 send buffer.

## Notes / uncertainty
Renamed from send_area_member_update_aux: STAGES (does not emit) aux channel. Per-conn slot conn[3]*0x824; gated by 0x3bfcec[area]; reliable attr preset (0x12=0x8000); allocs 0x20 buffer at 0x4290fc. FUN_001a7b70 attr-key meanings inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
