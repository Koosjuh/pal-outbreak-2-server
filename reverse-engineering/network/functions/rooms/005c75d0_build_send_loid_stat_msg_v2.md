# 0x005c75d0 build_send_loid_stat_msg_v2

| field | value |
|---|---|
| Original address | 0x005c75d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c75d0 |
| Resolved name | build_send_loid_stat_msg_v2 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c7540
**Callees:** FUN_005bf1e0, FUN_005c3e50
**Referenced globals:** 0x6405a8 (STAT payload); 0x640580; 0x6febac (conn); 0x7006a8; 0x700600 (reply ctx)
**Referenced strings:** LOID; STAT
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Phase-2 variant of the LOID/STAT send: same member-slot status upload but with DAT_006405a8 payload and reply cb FUN_005c7850.

## Notes / uncertainty
Phase-2 twin of 0x005c7320; differs only in field-1 payload DAT_006405a8, ctx 0x7006a8, reply handler 0x5c7850/ctx 0x700600. v1/v2 payload split semantics unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c75d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
