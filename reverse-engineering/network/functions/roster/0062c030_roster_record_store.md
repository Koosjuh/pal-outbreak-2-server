# 0x0062c030 roster_record_store

| field | value |
|---|---|
| Original address | 0x0062c030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c030 |
| Resolved name | roster_record_store |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062bda0
**Callees:** —
**Referenced globals:** +0x10b8 scratch member; +0x12c2 member array; +0x1460 idx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies the scratch member record (+0x10b8..+0x10bf then +0x10c0 0x81 bytes) into the member-list array at +0x12c2 + idx*0x8a, then increments the slot index.

## Notes / uncertainty
Commits scratch member (room+0x10b8: 3xu16+2xu8 header + 0x81 body) into member array room+0x12c2 at idx*0x8a; increments cursor, rewinds caller SM. Header field meanings not resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
