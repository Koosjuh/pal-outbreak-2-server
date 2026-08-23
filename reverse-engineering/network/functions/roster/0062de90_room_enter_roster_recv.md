# 0x0062de90 room_enter_roster_recv

| field | value |
|---|---|
| Original address | 0x0062de90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062de90 |
| Resolved name | room_enter_roster_recv |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d950
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005bd940, FUN_005c0400, FUN_005c0470, FUN_005c08a0, FUN_005c0960, FUN_005c0f20, FUN_0062e8e0
**Referenced globals:** 0x6970a0 roster table (stride 0x14a8); 0x6970f4 player count; 0x6c4b9c/0x6c4b94/0x343625 record fields; struct+0x1e50 enter-record
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x10 enter-step(0-0xb); struct+0x42b screen-id

## Behavioral explanation
Room enter/detail state machine with a ~166KB receive buffer; case4 parses the room roster: player count bRam006970f4, per-player records (stride 0x14a8) into table 0x6970a0 including names, char id, and 0x20x0x20 map/cell data.

## Notes / uncertainty
Room-enter SM (step room+0x10, 0-0xb). Case-4 parses ~0x29555 roster payload into 0x6970a0 (stride 0x14a8): count->0x6970f4 (rendered count), per-player name/char-id/sub-list/0x20x0x20 3-byte grid. Case-0xb registers 0x62eff0+0x62f1e0 handlers. Wire src layout (0x14a5 stride) reconstructed from copy offsets, not a captured payload.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062de90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
