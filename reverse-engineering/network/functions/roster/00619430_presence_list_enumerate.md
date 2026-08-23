# 0x00619430 presence_list_enumerate

| field | value |
|---|---|
| Original address | 0x00619430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619430 |
| Resolved name | presence_list_enumerate |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00619330
**Callees:** FUN_005af400, FUN_00604860
**Referenced globals:** 0x694700 name registry (stride 0x38, refcount +0x20); 0x7148f0/0x714900 working list; 0x874fc0 filter table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx[5] entry count

## Behavioral explanation
Step 1: enumerates up to 4 named entries (func_0x007df500), looks each up in registry table 0x694700, and either bumps a refcount or appends a new 16-byte name entry into the working list at 0x7148f0/0x714900.

## Notes / uncertainty
Phase 1: enumerates 4 sources, filters via 0x874fc0, dedups into registry 0x694700 (refresh+refcount) or stages new (id,name) in working list 0x7148f0/0x714900. func_0x007df500 source semantics and id width inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
