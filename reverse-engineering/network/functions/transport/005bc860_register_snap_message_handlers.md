# 0x005bc860 register_snap_message_handlers

| field | value |
|---|---|
| Original address | 0x005bc860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc860 |
| Resolved name | register_snap_message_handlers |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bcfd0, FUN_005bd2e0
**Callees:** —
**Referenced globals:** 0x6febac (connection/session handle)
**Referenced strings:** —
**Referenced opcodes:** 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0b, 0x0d, 0x0e, 0x13, 0x15
**State vars:** —

## Behavioral explanation
Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

## Notes / uncertainty
Installs 13 code->handler bindings on conn 0x6febac via FUN_001d4d24: 0x0d/0x0b->name-reg, 0x0e->name-simple, 0x02->member-join(5bb4d0), 0x06->leave/roster(5bb670), 0x0a->memberlist(5bc430), 0x13->inroom-subdispatch, 3/7 area-count, 04/05/08/15. Codes are post selector-3 dispatch keys, not raw wire opcodes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
