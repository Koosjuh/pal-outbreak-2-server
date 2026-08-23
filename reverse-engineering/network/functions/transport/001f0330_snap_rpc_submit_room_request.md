# 0x001f0330 snap_rpc_submit_room_request

| field | value |
|---|---|
| Original address | 0x001f0330 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0330 |
| Resolved name | snap_rpc_submit_room_request |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eea10
**Callees:** FUN_00109eb8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Compound SIF-RPC selector 0x21, 0x524 req = 0x24 header + 5x0x100 text/data blocks (name/pw/comment/payloads) + 3 scalars + id/len. EE create/enter-room submit. Block->field mapping inferred; 0x524=0x24+5*0x100 confirms layout.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
