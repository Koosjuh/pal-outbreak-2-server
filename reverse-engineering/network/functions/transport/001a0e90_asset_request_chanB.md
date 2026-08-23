# 0x001a0e90 asset_request_chanB

| field | value |
|---|---|
| Original address | 0x001a0e90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a0e90 |
| Resolved name | asset_request_chanB |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001a1750, FUN_001cb360
**Callees:** FUN_001a08d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Channel-B sibling of a0df0 on uRam0029bc18, no pre-step. Returns reply length. Whether B differs by format or only handle is unconfirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a0e90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
