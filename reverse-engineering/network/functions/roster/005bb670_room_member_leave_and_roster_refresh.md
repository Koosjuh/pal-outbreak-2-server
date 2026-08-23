# 0x005bb670 room_member_leave_and_roster_refresh

| field | value |
|---|---|
| Original address | 0x005bb670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb670 |
| Resolved name | room_member_leave_and_roster_refresh |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bb610, FUN_005bc370, FUN_005bdfe0, FUN_005bf1e0, FUN_005c50a0, FUN_005c5120, FUN_005c7d00
**Referenced globals:** 0x7006d4 (4x8 in-scenario player-id slots); 0x6cfb62 (per-area count A, stride 0x144); 0x6cfb70 (per-area member count, stride 0x144); 0x6cdbe6 (roster table, stride 0x28); 0x6cd672 (scratch roster entry); 0x6ff2b0 (mode flag); 0x70047c (lobby/in-game mode flag); 0x6fb746 (roster-visible count)
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** cRam0070047c; cRam006ff2b0

## Behavioral explanation
Handles member-leave (dispatch code 6): decrements per-area count, clears the departing player's id from the 4-slot in-scenario table (0x7006d4) and notifies via FUN_005bb610, or in the alt mode copies the matching roster entry into scratch and fires a roster redraw (0x25/0x23).

## Notes / uncertainty
Dispatch code 6 = member LEAVE (client-side; trumps old '0x06=JOIN' wire hint). Lobby path: decrement per-area counts 0x6cfb62/0x6cfb70, clear 0x7006d4 slot (host only), broadcast count. In-game path: remove 0x6cdbe6 entry, recount 0x6fb746. In-game loop index is Ghidra artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
