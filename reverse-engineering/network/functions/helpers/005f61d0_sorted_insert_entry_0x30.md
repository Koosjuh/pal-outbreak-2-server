# 0x005f61d0 sorted_insert_entry_0x30

| field | value |
|---|---|
| Original address | 0x005f61d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f61d0 |
| Resolved name | sorted_insert_entry_0x30 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f5fe0
**Callees:** —
**Referenced globals:** 0x70a150 (0x30-stride record table); 0x70a148 (sort-key column)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+10 (count, cap 100); param+8 (index)

## Behavioral explanation
Appends a 0x30-byte record into the table at 0x70a150 (cap 100) then bubble/insertion-sorts it descending by the uint key at record+0x28.

## Notes / uncertainty
Insertion-sort append into 0x30-stride table @0x70a150 (cap 100), ascending by u32 key at record+0x28, 3-memcpy swap via stack temp; full guard + <2-record short-circuit. 0x70a148 = base-8 aliases the predecessor key. Record's non-key fields and caller 005f5fe0's source data opaque. Client display/roster ordering; no wire.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f61d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
