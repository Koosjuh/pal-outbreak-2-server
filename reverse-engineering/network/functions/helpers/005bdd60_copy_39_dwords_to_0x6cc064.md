# 0x005bdd60 copy_39_dwords_to_0x6cc064

| field | value |
|---|---|
| Original address | 0x005bdd60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdd60 |
| Resolved name | copy_39_dwords_to_0x6cc064 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b6950
**Callees:** —
**Referenced globals:** 0x6cc064 39-dword table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies 39 dwords from the caller's buffer into global table 0x6cc064.

## Notes / uncertainty
Fixed 39-dword (0x9c-byte) import caller->global table 0x6cc064; count/direction certain, table purpose inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdd60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
