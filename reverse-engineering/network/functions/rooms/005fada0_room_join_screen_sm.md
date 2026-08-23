# 0x005fada0 room_join_screen_sm

| field | value |
|---|---|
| Original address | 0x005fada0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fada0 |
| Resolved name | room_join_screen_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa0b0
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005bd940, FUN_005c04f0, FUN_005c0750, FUN_005fb670, FUN_005fe500
**Referenced globals:** +0x1e50 join request block; +0x9a4 timeout ctr; +0x9a9 reply code; 0x6970a2 password buf; sRam006c4b94 sel slot
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state; +0x9a9 reply-outcome

## Behavioral explanation
Enter/join-room screen SM: builds request struct (@+0x1e50, memset 0xd4), sends join with password buffer 0x6970a2 (timeout 0x708), handles reply code @+0x9a9.

## Notes / uncertainty
Enter/join SM (+0x10): case0 builds 0xd4 request block +0x1e50 with slot area/section coords (cb 0x5fc4a0); case2 send_op6e_with_name(idx, password 0x6970a2) join; case4 dispatch outcome +0x9a9 (0 success->lobby,1 commit,2 password); case5/8 room_commit_send_stat_op70. Whether +0x1e50 block is detail-fetch vs create-slot unresolved; op6e+STAT sequence certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fada0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
