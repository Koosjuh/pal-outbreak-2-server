# 0x005c0400 create_room_enter_screen_set_host

| field | value |
|---|---|
| Original address | 0x005c0400 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0400 |
| Resolved name | create_room_enter_screen_set_host |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f91f0, FUN_0062de90
**Callees:** FUN_005bf0e0, FUN_005bf180
**Referenced globals:** 0x6ff2b0 host/create flag (=1); 0x7006d0 create scratch buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ff2b0 host flag

## Behavioral explanation
Enters the create-room screen: FUN_005bf0e0/5bf180 set room slot 2, sets host/create flag 0x6ff2b0=1, zeroes buffer 0x7006d0, then invokes the supplied completion callback.

## Notes / uncertainty
Pure state setup: commits room-slot reg 2, asserts host flag 0x6ff2b0=1, zeroes create scratch 0x7006d0, fires ok cb. No wire send. Whether slot2 gets new-room descriptor vs highlighted row unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0400.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
