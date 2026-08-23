# 0x001ef130 snap_call_f0890_pair

| field | value |
|---|---|
| Original address | 0x001ef130 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef130 |
| Resolved name | snap_call_f0890_pair |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c0b20
**Callees:** FUN_001f0890
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wrapper forwarding param_1 and a struct split (param_2, param_2+4) to FUN_001f0890.

## Notes / uncertainty
handle + (base,base+4) split to undecompiled f0890; setup-path bind inferred from 0x1c0b20 caller.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
