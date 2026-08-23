# 0x001a5bb0 reqqueue_enqueue_16

| field | value |
|---|---|
| Original address | 0x001a5bb0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a5bb0 |
| Resolved name | reqqueue_enqueue_16 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d2e90
**Callees:** FUN_001069a8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
8-slot request queue producer: reject on null ptr / mode cRam003435b5==2 / count>=8; writes 16B payload(0x29f314)+tag(0x29f2fc)+cleared status(0x29f304)+payload[+0xf], advances idx(wrap8), kicks consumer flag cRam0029f2f0 on first entry. Consumer/domain (DNS? mailbox) not captured.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a5bb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
