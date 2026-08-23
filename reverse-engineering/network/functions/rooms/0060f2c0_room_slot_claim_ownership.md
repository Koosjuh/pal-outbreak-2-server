# 0x0060f2c0 room_slot_claim_ownership

| field | value |
|---|---|
| Original address | 0x0060f2c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f2c0 |
| Resolved name | room_slot_claim_ownership |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610580, FUN_00610830
**Callees:** —
**Referenced globals:** piRam0035c3d8 (owned-room ptr); 0x35c000 (room table); +0x8 (open flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** piRam0035c3d8 ownership latch

## Behavioral explanation
Claims global owned-room pointer piRam0035c3d8 for room table[param_1] iff currently unowned, entry+0x8==1 (open) and entry+0=1 (live); returns 1 claimed, -2 not-claimable, or 0/-1 if already ours/foreign.

## Notes / uncertainty
Verified line-for-line: unowned+open(+0x08==1)+live(+0x00==1) -> latch piRam0035c3d8, fire 001bf5a0/590, ret 1; else -2; already-owned -> 0 (same) / -1 (diff). Whether +0x00/+0x08 are populated by op49 reply or a later step is the crux of the create blocker and is NOT runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f2c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
