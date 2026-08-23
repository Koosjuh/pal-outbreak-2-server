# 0x00614c70 noop_stub

| field | value |
|---|---|
| Original address | 0x00614c70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614c70 |
| Resolved name | noop_stub |
| Subsystem | unknown |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00614b90
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty function (returns immediately).

## Notes / uncertainty
Empty body fully recovered (lone return); raised to High since nothing behavioral is unknown, only why the slot exists.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614c70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
