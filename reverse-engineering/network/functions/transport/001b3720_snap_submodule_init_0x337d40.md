# 0x001b3720 snap_submodule_init_0x337d40

| field | value |
|---|---|
| Original address | 0x001b3720 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001b3720 |
| Resolved name | snap_submodule_init_0x337d40 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_00606af0, FUN_00606e40, FUN_006075e0, FUN_00608300, FUN_006088b0
**Callees:** FUN_00106b60, FUN_001b3ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
memset(0x337d40,0,0x18)+FUN_001b3ba0 init. Clear-then-construct pattern is certain; owning subsystem unresolved (FUN_001b3ba0 not decompiled).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001b3720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
