# 0x0062c160 roster_record_store_from_buf

| field | value |
|---|---|
| Original address | 0x0062c160 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c160 |
| Resolved name | roster_record_store_from_buf |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062bda0
**Callees:** —
**Referenced globals:** +0x5ec source buf; +0x12c2 member array; +0x1460 idx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a 0x81-byte member record from the +0x5ec work buffer into +0x12c2 + idx*0x8a and increments the slot index.

## Notes / uncertainty
Variant of 0062c030: copies ONLY the 0x81 body from room+0x5ec into record+0x08 (header left intact), advances cursor. Why header skipped unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
