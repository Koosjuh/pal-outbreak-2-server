# 0x006205c0 screen_sm_lobby_browse

| field | value |
|---|---|
| Original address | 0x006205c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006205c0 |
| Resolved name | screen_sm_lobby_browse |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e7f0, FUN_0061e910, FUN_0061e940, FUN_0061e960, FUN_0061ea20, FUN_0061f0d0, FUN_0061f0f0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f3b0, FUN_0061f3d0, FUN_0061f450, FUN_0061f4b0, FUN_0061f8d0, FUN_0061f970, FUN_0061f9d0, FUN_00620570
**Referenced globals:** 0x7152e1 substate; 0x7152e4 timer; 0x7152e6 timer; 0x7152f5 mode; 0x715360 handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; sRam007152e4; sRam007152e6; uRam007152f5

## Behavioral explanation
Large multi-state screen machine (lobby/room browse flow): sequences window fades, timers, hold-counter, and input across ~20 substates; returns 1/-1.

## Notes / uncertainty
~20-state room-list browse; pumps external list_query func_0x012307f0 (tri-state <0/=0/>=1) with phase f5=1/2/3. External query primitive not decompiled; SN@P mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006205c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
