# 0x001c0b20 resolve_local_endpoint

| field | value |
|---|---|
| Original address | 0x001c0b20 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0b20 |
| Resolved name | resolve_local_endpoint |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40, FUN_001c19e0
**Callees:** FUN_001c08a0, FUN_001ee720, FUN_001ee930, FUN_001ef130, FUN_001f1e40
**Referenced globals:** 0x35c3d8 mode; 0x35bcc0 local-ep; 0x35bec8 src-sel; 0x35bcb8/0x35bcb0 override
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35c3d8; 0x35bec8

## Behavioral explanation
Determines local IP/port for the connection by mode(0x35c3d8): copies configured (0x35bcc0), or queries stack via FUN_001ee930/ef130, then commits and refreshes DNS cache.

## Notes / uncertainty
Picks local ip/port into 0x35bcc0 by mode(0x35c3d8)+src-select(0x35bec8): configured (FUN_001ef130) vs stack-query (FUN_001ee930); overrides 0x35bcb0/0x35bcb8 win; commits via FUN_001ee720 then apply/refresh. Mode labels inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0b20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
