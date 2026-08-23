# 0x001f33e8 endpoint_set_mode

| field | value |
|---|---|
| Original address | 0x001f33e8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f33e8 |
| Resolved name | endpoint_set_mode |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d4380
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
setsockopt-style boolean-mode setter over per-endpoint table (base iRam0037e944, count 0037e940, stride 0x38); resets +0x14/+0x20/+0x2c/+0x30 + uRam0037e950 when mode changes. Owning subsystem (distinct from snap_connection and dbcman socket table) and mode 0/1 meaning unresolved; no caller in batch.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f33e8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
