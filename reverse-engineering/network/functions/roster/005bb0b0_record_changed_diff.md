# 0x005bb0b0 record_changed_diff

| field | value |
|---|---|
| Original address | 0x005bb0b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb0b0 |
| Resolved name | record_changed_diff |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae8a0
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base [cur=0, prev=1]
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Dirty-check: compares record[param_1] in table base(0) vs base(1): bytes 0-3, dwords +0x14/+0x18, strcmp +0x34, then bytes 4..0x14; returns 0 only if fully identical, 1 if any field differs.

## Notes / uncertainty
Redraw dirty-check comparing current(0)/previous(1) snapshots of the 0x1e4 record; unchanged(0) iff b0..b3,+0x14,+0x18,name@0x34,blob[0x10]@0x04 all equal. Defines the whole accessor family's field map.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb0b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
