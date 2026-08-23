# 0x00628f70 charsel_pick_sm

| field | value |
|---|---|
| Original address | 0x00628f70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628f70 |
| Resolved name | charsel_pick_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_00629160, FUN_0062a5c0, FUN_0062b9e0
**Referenced globals:** 0x6c555e room-player-count; param+0x9d2 char-blocks(0xa5); param+0xefa active-char
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006c555e player-count

## Behavioral explanation
Character-pick state machine: moves the selection index (clamped by FUN_00629160 against room player count bRam006c555e), and on confirm value 8/9 branches to sub-machines, else copies the 0xa5-byte character block into the active slot.

## Notes / uncertainty
Cursor-pick SM with 0xA5 char-block copy to ctx+0xefa; cursor sentinels 8/9 -> sub-machines. FUN_005b14b0 polarity and 0xa5 block layout inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628f70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
