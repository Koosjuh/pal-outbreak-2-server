# 0x001ee360 netlink_get_status

| field | value |
|---|---|
| Original address | 0x001ee360 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee360 |
| Resolved name | netlink_get_status |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0100
**Callees:** —
**Referenced globals:** 0x0037a298 status/error
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x0037a298 status/error

## Behavioral explanation
Getter for global link status/error code at 0x37a298 (set by FUN_001ee1e0).

## Notes / uncertainty
Getter for status/error global 0x37a298 (set by poller 1ee1e0). Status code enum not decoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
