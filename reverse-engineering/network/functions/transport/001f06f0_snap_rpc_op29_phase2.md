# 0x001f06f0 snap_rpc_op29_phase2

| field | value |
|---|---|
| Original address | 0x001f06f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f06f0 |
| Resolved name | snap_rpc_op29_phase2 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eee30
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x29; unusually writes arg to buffer base +0x00 not +0x1c, but sole caller FUN_001eee30 passes junk then sets SNAP phase var 0x37a288:=2. Header-word meaning unverified.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f06f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
