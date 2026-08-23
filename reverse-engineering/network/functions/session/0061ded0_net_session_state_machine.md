# 0x0061ded0 net_session_state_machine

| field | value |
|---|---|
| Original address | 0x0061ded0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061ded0 |
| Resolved name | net_session_state_machine |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604180, FUN_00619750, FUN_00628210, FUN_006296a0
**Callees:** FUN_001f46e0, FUN_005b8cf0, FUN_005b8da0, FUN_005b9110, FUN_0061d690, FUN_0061dd90, FUN_0061ddd0, FUN_0061ddf0, FUN_0061e630, FUN_0061e640, FUN_0061e650, FUN_0061e680, FUN_0061e6e0, FUN_0061e770, FUN_0061ea30
**Referenced globals:** cRam0071535c session-state; sRam007152e4 timer; sRam007152ea result cache; iRam003435e8 session buffer base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0071535c; sRam007152e4; sRam007152ea

## Behavioral explanation
Primary lobby/session connect state machine keyed on cRam0071535c: under a mutex it steps through a network op (FUN_0061e650 returning codes -0x100..-0xfb), keepalive/poll (FUN_0061e770/e6e0), send (FUN_0061e640/e680), branching to error/retry/success states.

## Notes / uncertainty
Core lobby session driver under mutex; loads 0x1d7c template 0x3c8a90; deferred-message mechanism (FUN_0061dd90 → state-pairs 0x64/6e/78); terminals 0x5a=1,0x5b/5c=-1. Decompiler default 'next=state+1' bookkeeping is model, not gospel.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061ded0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
