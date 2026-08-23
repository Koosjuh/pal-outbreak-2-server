# 0x005d7090 roster_reset

| field | value |
|---|---|
| Original address | 0x005d7090 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7090 |
| Resolved name | roster_reset |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c84e0
**Callees:** FUN_005d79e0
**Referenced globals:** 0x004f47c roster pool head
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper that flushes the entire roster pool (base+0x4f47c) via roster_clear_all.

## Notes / uncertainty
Trivial wrapper: roster_clear_all(pool head +0x4f47c). No material uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7090.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
