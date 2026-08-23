# 0x005dedc0 strncpy_255

| field | value |
|---|---|
| Original address | 0x005dedc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dedc0 |
| Resolved name | strncpy_255 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6630, FUN_005d6770, FUN_005d6c10, FUN_005d7e00, FUN_005d7f80, FUN_005d8340, FUN_005dee00, FUN_005df640
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies up to 0xff bytes from src to dst and forces a NUL terminator at [0xff] (bounded string copy).

## Notes / uncertainty
Already a full reconstruction: fixed 255-byte copy + NUL at [0xFF] into a 256-byte field via memcpy thunk func_0x0010a4f0. Left untouched. Thunk memcpy-vs-strncpy is the only residual ambiguity.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dedc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
