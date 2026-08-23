# 0x00606af0 session_login_state_machine

| field | value |
|---|---|
| Original address | 0x00606af0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606af0 |
| Resolved name | session_login_state_machine |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_001b3720, FUN_005af340, FUN_005b14b0, FUN_005b8cf0, FUN_00606a70, FUN_00606c80, FUN_00618b60, FUN_00618c30
**Referenced globals:** cRam006c4b9e (state); cRam0070cd80 (result code); cRam003c8a80 (abort flag); uRam0035a6f4 (socket)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b9e; cRam0070cd80

## Behavioral explanation
6-case session/login driver (cRam006c4b9e): issues reliable requests via FUN_005b8cf0 (offsets -0x63, 0x50), waits on async completion (FUN_00606a70), advances on specific result codes (cRam0070cd80 == -0x14d / -0x11), and re-fires (FUN_00606c80) on error, pumping the frame each step (FUN_00618c30).

## Notes / uncertainty
Connect-progress screen on lobby_sm 0x6c4b9e; advances on result codes cd80==-0x14d/-0x11, resets via FUN_00606c80 otherwise. Exact meaning of -0x14d vs -0x11 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606af0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
