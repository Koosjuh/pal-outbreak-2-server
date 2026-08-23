# 0x00617230 room_phase03_wait_tick

| field | value |
|---|---|
| Original address | 0x00617230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617230 |
| Resolved name | room_phase03_wait_tick |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x16 countdown; +0xe major-state; +0xf=0

## Behavioral explanation
Room phase-3: simple countdown on +0x16; on expiry advances major state and reloads timer to 0x96 (150).

## Notes / uncertainty
Pure dwell tick: decrement +0x16, on <0 bump major, reset minor, reload 0x96 (150f). No branches beyond the timer gate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
