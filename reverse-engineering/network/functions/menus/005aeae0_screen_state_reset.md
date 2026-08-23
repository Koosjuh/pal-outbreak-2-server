# 0x005aeae0 screen_state_reset

| field | value |
|---|---|
| Original address | 0x005aeae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aeae0 |
| Resolved name | screen_state_reset |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae770
**Callees:** FUN_00617a00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x5196/+0x5197/+0x5198; +0x51a2 sub-panel flag; +0x54b4..54bc sub-state

## Behavioral explanation
Resets the overlay screen state fields (+0x5196/97/98=0) and, if a sub-panel flag (+0x51a2) is set, clears its sub-fields; then calls a teardown helper.

## Notes / uncertainty
Phase-2 of 5197: clears 5196/97/98 and, if +0x51a2!=0, also the co-armed 54b4 fields; teardown FUN_00617a00. Notably leaves +0x51a2 set (unlike ae750) - reason unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aeae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
