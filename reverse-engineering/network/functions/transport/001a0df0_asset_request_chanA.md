# 0x001a0df0 asset_request_chanA

| field | value |
|---|---|
| Original address | 0x001a0df0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a0df0 |
| Resolved name | asset_request_chanA |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001a0eb0, FUN_001a1750, FUN_001cb360, FUN_001cd160, FUN_001cfc90, FUN_001d2b30, FUN_001d3240, FUN_001d3310, FUN_001d33d0, FUN_001d3500, FUN_001d3b40, FUN_001d3df0
**Callees:** FUN_001a08d0, FUN_001a0bf0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Channel-A request wrapper: FUN_001a0bf0(uRam0034357a) pre-step then FUN_001a08d0(uRam0029bc20,req,dest,0). Returns reply length (void is decompiler artifact; callers branch on >0). SIF-RPC vs socket unconfirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a0df0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
