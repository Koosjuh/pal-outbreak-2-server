# 0x005d72d0 roomlist_has_prev

| field | value |
|---|---|
| Original address | 0x005d72d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d72d0 |
| Resolved name | roomlist_has_prev |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d09d0
**Callees:** FUN_005d6810
**Referenced globals:** 0x004f588 roomlist head; 0x00701018 current room
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00701018

## Behavioral explanation
Predicate: true if the reverse room iterator (FUN_005d6810) from the current room yields a different node.

## Notes / uncertainty
Mirror of 005d71a0 using reverse iterator 005d6810; returns whether a previous room exists. Same multi-return caveat.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d72d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
