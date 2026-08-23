# 0x005bace0 return_zero_stub_e0

| field | value |
|---|---|
| Original address | 0x005bace0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bace0 |
| Resolved name | return_zero_stub_e0 |
| Subsystem | unknown |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005fcba0, FUN_005fe140
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stub returning 0 (8 bytes).

## Notes / uncertainty
8-byte return 0; live-called from list-draw fns 005fcba0/005fe140. Behavior certain; role (disabled per-entry attribute getter) inferred only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bace0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
