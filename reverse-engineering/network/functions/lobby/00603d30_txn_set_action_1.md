# 0x00603d30 txn_set_action_1

| field | value |
|---|---|
| Original address | 0x00603d30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00603d30 |
| Resolved name | txn_set_action_1 |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b1a30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+1 (action byte); ctx+0xe..0x11 (timeout counter)

## Behavioral explanation
Sets a room-context action/next-op byte at +1 to 1 and clears the 4-byte retry/timeout counter (+0xe..+0x11).

## Notes / uncertainty
One of a d30/d50/d70 triplet: sets room/txn ctx action byte +0x01=1 and clears 4-byte counter +0x0e..0x11. Write/clear certain; action=1 (register/create?) opcode mapping inferred, unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00603d30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
