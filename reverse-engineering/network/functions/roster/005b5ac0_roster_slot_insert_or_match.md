# 0x005b5ac0 roster_slot_insert_or_match

| field | value |
|---|---|
| Original address | 0x005b5ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5ac0 |
| Resolved name | roster_slot_insert_or_match |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0920, FUN_005c4d20
**Referenced globals:** cRam006c4b90 (mode); 0x6c7c2c/0x6c7c3c/0x6c7c50 (4-slot roster table, stride 0x3b0); 0x6c7d18/0x6c7d1a/0x6c7d20 (per-slot id/flag fields); cRam006c550e (send-enable gate)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c550e

## Behavioral explanation
In room modes (4/0x0e, and 5): scan the 4-slot member table (stride 0x3b0 @0x6c7c3c), match/insert a member entry (name@0x6c7c2c, tag@0x6c7c3c, data@0x6c7c50) and optionally emit via FUN_005c4d20.

## Notes / uncertainty
Local self-insert into 4-slot member_record roster (0x6c7c2c stride0x3b0). Screen 5=announce; 4/0x0e=match-by id0x6c7d18/flag0x6c7d1a (special 6<->0x5b pair rule) else insert first empty. want_id/want_flag origin (local record fields) split by Ghidra.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
