# 0x0062c3f0 roster_detail_load

| field | value |
|---|---|
| Original address | 0x0062c3f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c3f0 |
| Resolved name | roster_detail_load |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062c350
**Callees:** FUN_005b8da0
**Referenced globals:** +0x12c2 member array; +0x10b8 scratch; +0xefb/+0xf0b name fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads the selected member's record from +0x12c2 + sel*0x8a into the scratch +0x10b8 fields and name buffers (+0xefb/+0xf0b), opens a window and advances.

## Notes / uncertainty
Inverse of 0062c030: loads member[sel] (sel*0x8a confirmed via (sel*0x44+sel)*2) from +0x12c2 into scratch +0x10b8, plus name/id from 0x25-stride arrays +0x1045/+0x1055 into display +0xefb/+0xf0b; FUN_005b8da0(-0x50) send target unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c3f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
