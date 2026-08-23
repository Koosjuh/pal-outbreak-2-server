# 0x005be270 tick_active_task_slots

| field | value |
|---|---|
| Original address | 0x005be270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be270 |
| Resolved name | tick_active_task_slots |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005be330
**Callees:** —
**Referenced globals:** 0x6ca968 tick-cb; 0x6ca980 slot state; 0x6cb968 secondary cb table; 0x6cb98c secondary state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ca980 slot state==2; 0x6cb98c secondary active flag

## Behavioral explanation
Per-frame dispatcher: iterates all 128 task slots invoking the tick callback (+0x968) for those in state 2, then iterates a second 19-entry callback table at 0x6cb968/0x6cb98c firing active handlers.

## Notes / uncertainty
Per-frame pump. Loop1 (High): calls tick_cb for all slots with state==2. Loop2 (Low): sweeps ~19-entry secondary cb table @0x6cb968/0x6cb98c but decompiler emitted garbled index math ((iVar2+iVar3)*8); exact stride unconfirmed, flagged do-not-rely. Needs live disasm.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
