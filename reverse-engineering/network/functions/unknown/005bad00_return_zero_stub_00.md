# 0x005bad00 return_zero_stub_00

| field | value |
|---|---|
| Original address | 0x005bad00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bad00 |
| Resolved name | return_zero_stub_00 |
| Subsystem | unknown |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005af810
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stub returning 0 (8 bytes).

## Notes / uncertainty
8-byte return 0; single caller 005af810. Inferred stubbed predicate/accessor; role unproven, behavior certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bad00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
