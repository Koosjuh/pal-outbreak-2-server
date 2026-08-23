# 0x005c0960 room_enter_sm_arm

| field | value |
|---|---|
| Original address | 0x005c0960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0960 |
| Resolved name | room_enter_sm_arm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9280, FUN_005fa190, FUN_005fe8d0, FUN_0062de90
**Callees:** —
**Referenced globals:** 0x6cba54 SM guard; 0x6cba44 SM index; 0x6cba30 pump fnptr=FUN_005c3190; 0x6cba34 ctx; 0x6cba50 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cba54 guard

## Behavioral explanation
Arms an async screen state-machine keyed by index param_1: guard 0x6cba54, pump FUN_005c3190, ctx=param_2.

## Notes / uncertainty
CORE room enter/detail-fetch SM arm keyed by room index (0x6cba44), pump FUN_005c3190 fetches registry-B record idx*0x24+0x6fee68, host/join split on 0x6ff2b0. op0a-vs-op06 wire mapping not pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
