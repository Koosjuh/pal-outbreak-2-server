# 0x001bf230 streambuf_consume_compact

| field | value |
|---|---|
| Original address | 0x001bf230 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001bf230 |
| Resolved name | streambuf_consume_compact |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001caf60
**Callees:** FUN_00106a58, FUN_001bf1b0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Consume N bytes from front + memmove-compact tail; empty->FUN_001bf1b0 reset. Structure unambiguous; only FUN_001bf1b0 internals assumed. Not runtime-validated (cap High).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001bf230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
