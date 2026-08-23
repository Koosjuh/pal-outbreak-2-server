# 0x005c54e0 roster_add_member

| field | value |
|---|---|
| Original address | 0x005c54e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c54e0 |
| Resolved name | roster_add_member |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c51a0, FUN_005c5460
**Referenced globals:** 0x6fee8c roster-connid-key
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
On a member-present event (flag 0x80000): finds existing slot by connID or first free of 30, writes it via roster_slot_write, then refreshes UI.

## Notes / uncertainty
Member-present/JOIN handler: gated by status byte==0 and flag 0x80000; ghost flag 0x40000000 skips re-add; 30 slots keyed on connID 0x6fee8c. Which dispatch code binds it (shared member body op06/op0a) not yet confirmed vs register_snap_message_handlers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c54e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
