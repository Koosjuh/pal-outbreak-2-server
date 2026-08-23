# 0x00603d70 txn_set_action_6

| field | value |
|---|---|
| Original address | 0x00603d70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00603d70 |
| Resolved name | txn_set_action_6 |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b1a30, FUN_006052f0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+1; ctx+0xe..0x11

## Behavioral explanation
Sets room-context action byte at +1 to 6 (candidate enter/op06) and clears the retry counter.

## Notes / uncertainty
Sibling setter: ctx+0x01=6, clears +0x0e counter. Value 6 aligns with op06 member-JOIN/enter (inferred). Likely a different ctx struct than lobby_screen_dispatch's +1, since 6/7 aren't handled there.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00603d70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
