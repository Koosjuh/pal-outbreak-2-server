# 0x00606ac0 login_state_reset (alt: lobby_screen_sm_reset)

| field | value |
|---|---|
| Original address | 0x00606ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606ac0 |
| Resolved name | login_state_reset (alt: lobby_screen_sm_reset) |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006075e0, FUN_00608300, FUN_006088b0
**Callees:** FUN_00606a50
**Referenced globals:** uRam006c4b9e (login state); uRam006c4b9f/ba0/ba1; uRam006c4faa (retry)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b9e

## Behavioral explanation
Resets the login/session sub-state machine block (0x6c4b9e/9f/a0/a1, retry 0x6c4faa=8) and the async op state (FUN_00606a50).

## Notes / uncertainty
Resets lobby_state_block SM tuple (lobby_sm/screen_major/screen_step=0, top_screen=8) + async slot. 'login' name predates struct map; lobby_screen_sm_reset more accurate. Meaning of 0x6c4ba1 and top_screen=8 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
