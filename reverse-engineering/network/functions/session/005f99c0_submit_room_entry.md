# 0x005f99c0 submit_room_entry

| field | value |
|---|---|
| Original address | 0x005f99c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f99c0 |
| Resolved name | submit_room_entry |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9150
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005bd940, FUN_005c0470, FUN_005c08a0, FUN_005fe500
**Referenced globals:** param+0x1e50 (entry record, 0xd4); 0x6970a2/0x6970b2 (name buffers); 0x6970f4 (member count); 0x6c4b94 (local slot); 0x343625/0x343571
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x10

## Behavioral explanation
SM on +0x10: assembles the local player's entry record at +0x1e50 (0xd4 bytes: portrait/color/id from sRam006c4b94 tables, bRam00343625) and submits it (FUN_005bd940 cb 0x5fc4a0), plus name/member payloads via FUN_005c08a0/FUN_005c0470 (buffers 0x6970a2/b2), completing the room-join into the game.

## Notes / uncertainty
3-phase room-join submit: 0xd4 entry record (FUN_005bd940), party-mode|id word (0x10000/0x20000), name+roster (FUN_005c0470), then finalize FUN_005fe500. FUN_005c08a0 called 2-arg+cb here (send) vs its 1-arg setter record — needs confirmation.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f99c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
