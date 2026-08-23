# 0x005cf5f0 clear_link_state_3c8a80

| field | value |
|---|---|
| Original address | 0x005cf5f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cf5f0 |
| Resolved name | clear_link_state_3c8a80 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d3930
**Callees:** —
**Referenced globals:** 0x3c8a80 link state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x3c8a80

## Behavioral explanation
Clears the global link/connection-state byte 0x3c8a80 to 0.

## Notes / uncertainty
One-line: global link-state byte 0x3c8a80=0 (inactive); same flag gated by FUN_005cf1e0/FUN_005cc980. Non-zero value domain not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cf5f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
