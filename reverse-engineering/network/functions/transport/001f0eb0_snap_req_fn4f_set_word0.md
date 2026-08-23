# 0x001f0eb0 snap_req_fn4f_set_word0

| field | value |
|---|---|
| Original address | 0x001f0eb0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0eb0 |
| Resolved name | snap_req_fn4f_set_word0 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef2b0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
RPC stub fno 0x4f: setter with arg at tx+0x00 (not +0x1c); pairs with 0x4d getter's rx+0x00 slot. Meaning inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0eb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
