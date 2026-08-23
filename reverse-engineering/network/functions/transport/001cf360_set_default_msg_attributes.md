# 0x001cf360 set_default_msg_attributes

| field | value |
|---|---|
| Original address | 0x001cf360 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf360 |
| Resolved name | set_default_msg_attributes |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce970, FUN_001cef80, FUN_001cf3e0, FUN_001cf7c0, FUN_001cf8e0
**Callees:** FUN_001a7b70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Programs the standard outgoing-message attribute set via 8 FUN_001a7b70(key,val) calls (0x15=2,1=0x800,0x12=0x8000,0xc=0,0x66=1,0x62=1,0,2).

## Notes / uncertainty
8 fixed msg_set_attr(key,val) preset before sends; individual attribute-key semantics inferred (0x12=0x8000 may be reliable-bit).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
