# 0x00617bb0 entity_list_arm_timeouts

| field | value |
|---|---|
| Original address | 0x00617bb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617bb0 |
| Resolved name | entity_list_arm_timeouts |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00617110
**Callees:** FUN_005b8130, FUN_005ba7b0
**Referenced globals:** 0x654210 (entity/handle list head)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x654210 list; +0x30/+0x34 per-entry state/timeout

## Behavioral explanation
Walks the DAT_00654210 entity/handle list; for each resolved entry sets a timeout/state pair, using a special value (0x22==0xad -> -10/2) else default 1.

## Notes / uncertainty
Walks DAT_00654210 id-list (12B stride, neg id terminates), resolves each via FUN_005b8130, arms +0x30 state (=2/=1) and +0x34 timeout(-10) when entity+0x22==0xad. Resolve-fail bails without finalize (FUN_005ba7b0). 0xad meaning and entity fields inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617bb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
