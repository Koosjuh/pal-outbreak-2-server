# 0x005b3ed0 roomjoin_state2_enter

| field | value |
|---|---|
| Original address | 0x005b3ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3ed0 |
| Resolved name | roomjoin_state2_enter |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b3c30
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005b45f0, FUN_005b47a0, FUN_005b4c80, FUN_005b6c90, FUN_005b7fd0, FUN_005b9110, FUN_005ba570, FUN_005ba7b0, FUN_00618b60
**Referenced globals:** 0x6c4674 room-meta table
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** widget+1 phase; widget+7 room idx; struct+0x43c slot/result; struct+0x443 flag

## Behavioral explanation
Join phase 2: full enter-room flow — builds list/prompt widgets, checks slot availability (+0x43c), handles the join handshake and password/retry sub-widgets (0x5b45f0/47a0).

## Notes / uncertainty
Phase 2 enter/confirm SM: yes/no prompt (obj+0x43c), enter txn FUN_005b47a0 (client op06/member-JOIN path, inferred), cancel rebuilds picker; case6 meta[idx]!=0 -> return 1 (advance). FUN_005b47a0 emitting op06 not traced; create is separate phase 3.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
