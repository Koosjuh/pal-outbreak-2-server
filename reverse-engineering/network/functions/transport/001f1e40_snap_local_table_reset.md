# 0x001f1e40 snap_local_table_reset

| field | value |
|---|---|
| Original address | 0x001f1e40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f1e40 |
| Resolved name | snap_local_table_reset |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c0b20
**Callees:** FUN_00106b60, FUN_001f0f60, FUN_001f0f70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Clears EE-local SN@P table: memset 0x9a0 @0x37df50, clears count@0x37df48, under lock 0x0f60/0x0f70. In SN@P IPC region (queue 0x37df10). Record layout inside table undetermined.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f1e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
