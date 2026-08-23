# 0x001ab460 record_pool_reserve

| field | value |
|---|---|
| Original address | 0x001ab460 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ab460 |
| Resolved name | record_pool_reserve |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001a0eb0, FUN_001cf3e0, FUN_001cf570, FUN_001cf6a0, FUN_001cf7c0, FUN_001cf8e0, FUN_001cfa30, FUN_001cfb30, FUN_001cfc90, FUN_001d0040, FUN_001d0230, FUN_001d0400
**Callees:** FUN_001ab3d0, FUN_001ac0b0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Reserves param_1 records of stride 0x98(152B) from arena 0x2a4a10, registers in parallel ptr/size/type tables (cap 100, type=param_2+1); dedup via FUN_001ab3d0; aborts via FUN_001ac0b0 on pool-full/arena-exhausted. Whether these are SN@P member/room records is unconfirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001ab460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
