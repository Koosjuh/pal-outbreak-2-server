# 0x006195b0 presence_list_prune

| field | value |
|---|---|
| Original address | 0x006195b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006195b0 |
| Resolved name | presence_list_prune |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00619330
**Callees:** FUN_006049b0, FUN_00604a80, FUN_006277a0
**Referenced globals:** 0x694700 registry; 0x7148f0/0x714900 working list
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx[5] count

## Behavioral explanation
Step 2: walks the working list, finds stale entries in registry 0x694700 and removes them; if any removed, triggers a follow-up (FUN_006277a0).

## Notes / uncertainty
Phase 2: commits staged working-list entries into registry (FUN_006049b0/00604a80); on any change rebuilds display table via 0x6277a0. Commit-vs-find contract of callees inferred; name 'prune' reflects cycle role.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006195b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
