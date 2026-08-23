# 0x001c00e0 set_boot_arg

| field | value |
|---|---|
| Original address | 0x001c00e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c00e0 |
| Resolved name | set_boot_arg |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0100
**Callees:** —
**Referenced globals:** 0x35a6a8 boot-arg
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35a6a8

## Behavioral explanation
Trivial setter: stores param into global 0x35a6a8 (boot arg / resolved addr passed from state 1).

## Notes / uncertainty
Setter for 0x35a6a8; called from step-machine state 1 'resolved' branch with 0x35ba98. Semantic type of resolved value unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c00e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
