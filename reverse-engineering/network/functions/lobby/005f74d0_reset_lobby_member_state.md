# 0x005f74d0 reset_lobby_member_state

| field | value |
|---|---|
| Original address | 0x005f74d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f74d0 |
| Resolved name | reset_lobby_member_state |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad9f0, FUN_005adbe0, FUN_0062e720
**Callees:** FUN_005aec20, FUN_005af120
**Referenced globals:** 0x6c4b90 (screen state, mode=2); 0x6c3030 (member table, 0x828); 0x6c5490; 0x6c45fc; 0x6c4600
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90

## Behavioral explanation
Resets the lobby/room UI: sets 0x6c4b90 mode=2, clears the member table 0x6c3030 (0x828 bytes) and 0x6c5490 (0x20), re-inits via FUN_005aec20/FUN_005af120.

## Notes / uncertainty
Drops to lobby list screen (screen_id=2), clears member/roster table 0x6c3030 (0x828) + 0x6c5490 (0x20), re-arms via FUN_005aec20/005af120. Aux flags 0x6c45fc/0x6c4600 semantics open; relationship of 0x6c3030 to the drawn-row table 0x6c7c2c not pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f74d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
