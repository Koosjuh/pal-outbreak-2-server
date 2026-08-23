# 0x001c7a70 snap_recv_member_list_entries

| field | value |
|---|---|
| Original address | 0x001c7a70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c7a70 |
| Resolved name | snap_recv_member_list_entries |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3a60, FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x365e0c=cur-page/slot idx; 0x3619d0=slot-owner table[0x40]; 0x365f78=per-page member count; 0x365f80=member record base(0x134 each); 0x365e10/e12/e18=cursor idxs; 0x365f78=total count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35ccb4=create-in-progress flag; piVar7+0xd=substate; piVar7[3]=topstate

## Behavioral explanation
Parses room/member-list reply entries from the wire into 0x134-byte member records and distributes them across the 0x40-slot participant table.

## Notes / uncertainty
Already fully reconstructed. Paged op20 member-list receiver; fills 0x134 member records, owner-table 0x3619d0 with global 0x40 cap + eviction, page struct stride 0x260. Open: LAB_001c7e24 eviction priority order; create_in_progress topstate-4 semantics.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c7a70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
