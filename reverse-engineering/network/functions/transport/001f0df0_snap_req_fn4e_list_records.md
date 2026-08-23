# 0x001f0df0 snap_req_fn4e_list_records

| field | value |
|---|---|
| Original address | 0x001f0df0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0df0 |
| Resolved name | snap_req_fn4e_list_records |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef230
**Callees:** FUN_001069a8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
RPC stub fno 0x4e: list query, category 0..4 -> up to 4 records of 0x30c bytes; status word doubles as count; 0xffff on error. Possible mutex-leak on error paths (unlock only in success branch) flagged. Record identity (room/member) undetermined.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0df0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
