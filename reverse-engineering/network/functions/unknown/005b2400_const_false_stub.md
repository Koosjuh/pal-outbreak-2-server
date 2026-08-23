# 0x005b2400 const_false_stub

| field | value |
|---|---|
| Original address | 0x005b2400 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2400 |
| Resolved name | const_false_stub |
| Subsystem | unknown |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005f3e30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stub returning 0 (constant false), called by 0x5f3e30.

## Notes / uncertainty
Always-returns-0 stub used by caller 0x5f3e30 as a gate; reads as a compiled-in-but-disabled feature hook. What it would enable is unknown (needs caller branch analysis); may be a linker-patched stub.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2400.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
