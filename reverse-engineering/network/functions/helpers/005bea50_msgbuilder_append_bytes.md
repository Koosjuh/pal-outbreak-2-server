# 0x005bea50 msgbuilder_append_bytes

| field | value |
|---|---|
| Original address | 0x005bea50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bea50 |
| Resolved name | msgbuilder_append_bytes |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_00606780
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty stub (returns).

## Notes / uncertainty
Inert slot. Called (0x7018d0,buf,10) in FUN_00606780 to append a 10-byte formatted field to the 0x1031 reply. Role inferred from callsite; no writes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bea50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
