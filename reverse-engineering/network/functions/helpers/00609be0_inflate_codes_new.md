# 0x00609be0 inflate_codes_new

| field | value |
|---|---|
| Original address | 0x00609be0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00609be0 |
| Resolved name | inflate_codes_new |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00608c80
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflate_codes_new: ZALLOCs the 0x1c code-decoder struct and stores lbits/dbits/ltree/dtree.

## Notes / uncertainty
zlib. ZALLOC 0x1c code-decoder, stores lbits/dbits/ltree/dtree. Decompiler dropped the pointer return; inferred from zlib contract + caller store.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00609be0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
