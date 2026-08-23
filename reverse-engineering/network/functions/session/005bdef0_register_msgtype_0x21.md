# 0x005bdef0 register_msgtype_0x21

| field | value |
|---|---|
| Original address | 0x005bdef0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdef0 |
| Resolved name | register_msgtype_0x21 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bd8c0, FUN_005bd940
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea60, FUN_005bea80
**Referenced globals:** 0x7018d0 object registry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers a message/object of type 0x21 into 0x7018d0 (with a name/param pair) and returns the assigned short id.

## Notes / uncertainty
Registers named type 0x21 (name/param via 005bea60) into 0x7018d0, returns id=0x21 (begin-stub 005be9e0 is identity). Return consumed by 005bd940 as slot short-id. Identity stub means all sites return same id — real id assignment may be elsewhere.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdef0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
