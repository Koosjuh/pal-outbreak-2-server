# 0x005af810 query_5bad00

| field | value |
|---|---|
| Original address | 0x005af810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af810 |
| Resolved name | query_5bad00 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f5970, FUN_005fcba0, FUN_005fe140, FUN_00602700, FUN_006050d0
**Callees:** FUN_005bad00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper returning a byte from FUN_005bad00 — a status/availability query used by several screens.

## Notes / uncertainty
Trivial byte-narrowing forwarder over FUN_005bad00; behavior High but returned flag's meaning lives entirely in the unclassified callee.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
