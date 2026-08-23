# 0x005c3e50 store_handle_pair

| field | value |
|---|---|
| Original address | 0x005c3e50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3e50 |
| Resolved name | store_handle_pair |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bf470, FUN_005c0ff0, FUN_005c14a0, FUN_005c1770, FUN_005c7020, FUN_005c7320, FUN_005c75d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If handle>=0, writes the (handle, value) pair into the caller's out struct; generic success-return helper.

## Notes / uncertainty
Commits {handle,value} to out[2] only if handle>=0 (negative=-1 error sentinel, leaves out untouched). param_2 semantic varies by caller.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3e50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
