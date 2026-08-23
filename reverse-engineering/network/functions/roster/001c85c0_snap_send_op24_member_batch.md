# 0x001c85c0 snap_send_op24_member_batch

| field | value |
|---|---|
| Original address | 0x001c85c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c85c0 |
| Resolved name | snap_send_op24_member_batch |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3da0, FUN_001c4020, FUN_001ee590
**Referenced globals:** 0x365e1a=batch count; 0x365e18=sent cursor; 0x365e10=base idx; 0x365f78=total; 0x365f80=record base; 0x365e20=trailer
**Referenced strings:** —
**Referenced opcodes:** 0x24
**State vars:** iVar2+0xd=substate

## Behavioral explanation
Builds and sends the op-0x24 packet carrying up to 12 accumulated member-record pointers (a member-list batch/ack), then advances substate to 0xd.

## Notes / uncertainty
Already fully reconstructed. Emits op24 with up to 12 member records from current page + page descriptor; success -> substate 0x0d. Open: op24 = ack vs request-more; exact field put_string_field selects.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c85c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
