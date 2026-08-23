# 0x005c3e80 copy_user_identity_strings

| field | value |
|---|---|
| Original address | 0x005c3e80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3e80 |
| Resolved name | copy_user_identity_strings |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b5520, FUN_005b5690
**Callees:** —
**Referenced globals:** 0x6fbdac / 0x6fbdbc / 0x6fbdd0 (stored user id/name/handle strings)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies up to three fixed user identity strings (0x6fbdac/0x6fbdbc/0x6fbdd0) into the caller's non-null out pointers.

## Notes / uncertainty
Optional strcpy of 3 stored identity strings (0x6fbdac/bdbc/bdd0) into non-null out ptrs. Field identities (name/id/handle) inferred from size/adjacency, not proven -> Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3e80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
