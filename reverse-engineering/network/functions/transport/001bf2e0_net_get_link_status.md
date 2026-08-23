# 0x001bf2e0 net_get_link_status

| field | value |
|---|---|
| Original address | 0x001bf2e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001bf2e0 |
| Resolved name | net_get_link_status |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c4100
**Callees:** FUN_001eeb50
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Fills 4 out-params from active ifdesc (piRam0035c3d8): 2 cfg shorts, link-up bit (0x36d560&1), and metric/100 when state==2/3 via FUN_001eeb50(RPC 0x23). /100 unit inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001bf2e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
