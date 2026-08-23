# 0x006063c0 lobby_conn_state_dispatch

| field | value |
|---|---|
| Original address | 0x006063c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006063c0 |
| Resolved name | lobby_conn_state_dispatch |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_005f4480, FUN_006064c0, FUN_00606520, FUN_00606610, FUN_00606720, FUN_00606780, FUN_00606980, FUN_006069b0
**Referenced globals:** sRam0070cdc8 (conn state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** sRam0070cdc8

## Behavioral explanation
Top-level lobby-connection dispatcher: switches on sRam0070cdc8 (0..6, 99) to the corresponding step handler (init/connect-retry/await/post-connect/handshake/advance/error-reset), returning done when state 6 hits the re-init thunk.

## Notes / uncertainty
Top-level lobby-login sequencer on sRam0070cdc8 (0-6,99); state6=done(return1), 99=error-reset. Handlers for states 2/3/5 not decoded in this set.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006063c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
