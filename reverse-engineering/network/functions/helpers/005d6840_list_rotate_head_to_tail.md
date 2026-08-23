# 0x005d6840 list_rotate_head_to_tail

| field | value |
|---|---|
| Original address | 0x005d6840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6840 |
| Resolved name | list_rotate_head_to_tail |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d68e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x41

## Behavioral explanation
Generic helper: detaches the head node, appends/reinserts it cleared at the tail, and fixes up the passed cursor.

## Notes / uncertainty
Rotate first real node to tail, free it, fix caller cursor if it pointed at moved node.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
