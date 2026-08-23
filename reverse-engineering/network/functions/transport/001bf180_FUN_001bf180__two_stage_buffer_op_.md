# 0x001bf180 FUN_001bf180 (two-stage buffer op)

| field | value |
|---|---|
| Original address | 0x001bf180 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001bf180 |
| Resolved name | FUN_001bf180 (two-stage buffer op) |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_001caf30
**Callees:** FUN_001bfe00, FUN_001bfe10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Forwarder: FUN_001bfe00() then FUN_001bfe10(arg). Both callees not in export -> domain opaque; control flow certain.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001bf180.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
