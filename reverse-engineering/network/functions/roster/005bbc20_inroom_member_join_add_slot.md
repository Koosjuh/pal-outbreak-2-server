# 0x005bbc20 inroom_member_join_add_slot

| field | value |
|---|---|
| Original address | 0x005bbc20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bbc20 |
| Resolved name | inroom_member_join_add_slot |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005bdf90, FUN_005bdfe0, FUN_005bf1e0, FUN_005c4f00, FUN_005c6050, FUN_005c60d0
**Referenced globals:** 0x7006d4 (4x8 member-id slots); 0x6cfb70 (per-area member count); 0x7006a5 (start threshold); 0x6ff2b0 (mode flag); 0x6cbc7e/0x6cbc84 (UI status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006ff2b0; bRam007006a5

## Behavioral explanation
Sub-event 2: inserts a member id into the 4-slot table (0x7006d4) if absent, updates the per-area member count (0x6cfb70, capped at 4), broadcasts the new count to the other members (FUN_005c60d0), and may trigger start (FUN_005bdf90) once threshold reached.

## Notes / uncertainty
Sub-event 2 = member JOIN: insert id into 4-slot 0x7006d4 if absent, bump count 0x6cfb70 (cap4), broadcast to peers (FUN_005c6050 self / FUN_005c60d0 peer), UI 0x21, host auto-start when count>=threshold 0x7006a5. FUN_005c4f00 gate meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bbc20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
