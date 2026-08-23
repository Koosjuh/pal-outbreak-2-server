# 0x005c5390 roster_slot_clear

| field | value |
|---|---|
| Original address | 0x005c5390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5390 |
| Resolved name | roster_slot_clear |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c5610
**Callees:** —
**Referenced globals:** 0x6fee6c roster-tokens; 0x6cfb58 room-member-tbl; 0x6cfa30 slot-valid; 0x6cfa1c slot-index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes a roster slot (0x24 bytes @0x6fee6c and 0x144 bytes @0x6cfb58) and re-inits it as free with its index.

## Notes / uncertainty
Inverse of slot_write; caller passes a 1-based slot so id-table is indexed slot-1 while display valid/index fields (0x6cfa30/0x6cfa1c) use slot*0x144. valid-flag=1 meaning (free vs occupied) inferred from leave context.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5390.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
