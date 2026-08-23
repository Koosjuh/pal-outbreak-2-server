# 0x00600aa0 next_selectable_member_slot

| field | value |
|---|---|
| Original address | 0x00600aa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600aa0 |
| Resolved name | next_selectable_member_slot |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00600b60
**Callees:** —
**Referenced globals:** 0x6c7c3c room member table (0x3b0 stride); 0x6c8afc compare key
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Cycles a member-slot index (mod 4, up/down per param2) up to 5 times to find the next occupied+matching slot in the 0x3b0-stride room-member table at 0x6c7c3c.

## Notes / uncertainty
Cycles slot index mod 4 up to 5 steps for next occupied+key-matching grid slot (0x6c7c3c/0x3b0, key 0x6c8afc). Meaning of compare key (self vs filter) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600aa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
