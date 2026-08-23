# 0x005f08c0 ui_find_group_member

| field | value |
|---|---|
| Original address | 0x005f08c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f08c0 |
| Resolved name | ui_find_group_member |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f0930, FUN_005f10a0
**Callees:** —
**Referenced globals:** node+0x4 child head; node+0x8 next; node+0x48 span, +0x4c key
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans a node's child list for a member whose key +0x4c matches and whose span +0x48>=2; returns match or 0.

## Notes / uncertainty
Scans parent child list (via +0x04->+0x0c, +0x08) for matching key +0x4c with span+0x48>=2. Owner indirection inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f08c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
