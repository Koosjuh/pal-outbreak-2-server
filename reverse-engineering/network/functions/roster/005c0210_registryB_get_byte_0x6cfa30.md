# 0x005c0210 registryB_get_byte_0x6cfa30

| field | value |
|---|---|
| Original address | 0x005c0210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0210 |
| Resolved name | registryB_get_byte_0x6cfa30 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5860, FUN_005fc0c0, FUN_0062e9b0, FUN_0062edc0
**Callees:** —
**Referenced globals:** 0x6cfa30 registry-B render struct byte field (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 8-bit field at idx*0x144+0x6cfa30 (registry-B render-struct family) into out-ptr.

## Notes / uncertainty
u8 read registry-B +0x12; completes third family's row head.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
