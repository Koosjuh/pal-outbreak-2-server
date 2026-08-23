# 0x001c8790 snap_recv_member_list_page2

| field | value |
|---|---|
| Original address | 0x001c8790 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c8790 |
| Resolved name | snap_recv_member_list_page2 |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3a60, FUN_001c3ab0, FUN_001c3b90
**Referenced globals:** 0x365e0c=page idx; 0x365e10/e1a=cursors; 0x365f78=count; 0x365f80=record base; 0x365e20=trailer; 0x365e1e=page count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** piVar6+0xd=substate; piVar6[3]=topstate

## Behavioral explanation
Second-phase member-list receive: reads trailing u16 field (+0x12c) per record and a 0x3e-byte page trailer into 0x365e20, then pages the cursor or advances to next page.

## Notes / uncertainty
Already fully reconstructed. Second-phase member-list receive: per-record +0x12c u16 tail + 0x3e-byte page trailer; page routing 0x0c/0x10/0x31. Open: meaning of +0x12c field and 0x3e trailer contents.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c8790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
