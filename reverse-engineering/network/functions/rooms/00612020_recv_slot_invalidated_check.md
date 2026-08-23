# 0x00612020 recv_slot_invalidated_check

| field | value |
|---|---|
| Original address | 0x00612020 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00612020 |
| Resolved name | recv_slot_invalidated_check |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_00618230, FUN_00618520
**Referenced globals:** ctx+0x10d8 (dialog obj); ctx+0x10da/0x10db (avail bitmask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x10da/0x10db availability

## Behavioral explanation
Polls the room dialog (FUN_00618230); returns 1 if a fresh recv arrived AND the currently-selected slot (FUN_00618520) is NOT set in the availability bits derived from +0x10da|+0x10db, else 0.

## Notes / uncertainty
Returns 1 iff a fresh async recv arrived AND selected slot's availability bit (((m0|m1)>>1)&3 & 1<<unit) is CLEAR (invalidated); 0 otherwise/no-recv. 2-bit avail field meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00612020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
