# 0x001e40b0 socket_ioctl_bytesavail

| field | value |
|---|---|
| Original address | 0x001e40b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e40b0 |
| Resolved name | socket_ioctl_bytesavail |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_00103de8, FUN_001e2a28, FUN_001ebca8, FUN_001ebd54
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0x7f established

## Behavioral explanation
ioctl FIONREAD-equivalent: for an established socket, request 0x71045ead returns the byte-length of the head RX queue node into *param_3.

## Notes / uncertainty
FIONREAD-class ioctl (req 0x71045ead) returns head RX-node byte length for established (state 0x7f) socket; errno 0x6c/0x16/0x9. Reports head node only, not total.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e40b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
