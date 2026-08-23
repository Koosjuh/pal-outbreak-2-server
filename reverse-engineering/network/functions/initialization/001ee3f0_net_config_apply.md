# 0x001ee3f0 net_config_apply

| field | value |
|---|---|
| Original address | 0x001ee3f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee3f0 |
| Resolved name | net_config_apply |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c3850
**Callees:** FUN_001ee150, FUN_001ef610
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Unpacks a small config struct (u32 + two u16 at +4/+6) and passes to FUN_001ef610 (apply address/port/config), result forwarded through the passthrough.

## Notes / uncertainty
Unpacks 8B config {u32@0,u16@4,u16@6} -> FUN_001ef610 (addr/port/opt apply, inferred). Field offsets solid; primitive semantics undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee3f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
