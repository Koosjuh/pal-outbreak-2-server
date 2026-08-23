# 0x0017f158 dbcman_open

| field | value |
|---|---|
| Original address | 0x0017f158 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017f158 |
| Resolved name | dbcman_open |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017e5f8
**Callees:** FUN_00115c68, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sync RPC fn0x301 OPEN: serialises 5-word header + 16B addr + two params (type, type+0x80) into 0x27b000 scratch; returns endpoint handle at +0x24. Init-gated. Descriptor header[2..4] opaque.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017f158.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
