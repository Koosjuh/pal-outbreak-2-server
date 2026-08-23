# 0x005c3c40 copy_cast_row_names

| field | value |
|---|---|
| Original address | 0x005c3c40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3c40 |
| Resolved name | copy_cast_row_names |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c3b10
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Inner loop that copies each cast entry's name/graphic bytes (from 0x120-stride records) into the display buffer using a per-descriptor selector byte.

## Notes / uncertainty
Cast-row variant-byte blit into display buffer. Control flow exact; cast-record field offsets (+0x1d dst,+0x1e len,+0x3e variant table @0x20 stride) inferred from usage, no independent struct. param_2 variant-stream source unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3c40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
