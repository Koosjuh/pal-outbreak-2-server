# 0x00603e40 roster_ctx_state_machine

| field | value |
|---|---|
| Original address | 0x00603e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00603e40 |
| Resolved name | roster_ctx_state_machine |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005f8d40, FUN_005fe620, FUN_005ff950
**Callees:** FUN_00603f30, FUN_00604180, FUN_00618b60
**Referenced globals:** ctx+0x907..0x909; ctx+0x44c; ctx+0x10b3
**Referenced strings:** —
**Referenced opcodes:** 0x0c, 0x04
**State vars:** ctx+0xe (phase); ctx+1 (busy); ctx+0 (opcode)

## Behavioral explanation
Two-phase room-context driver: state0 seeds the member table (FUN_00603f30) and enters state1; state1 pumps the member-sync SM (FUN_00604180) and on completion branches on opcode 0x0c/0x04 to pick the next state.

## Notes / uncertainty
Two-phase room-txn driver: phase0 seeds member table (00603f30)+arm; phase1 pumps member-sync engine 00604180 and on done dispatches opcode 0x0c/0x04/else to next sub-state (identical body to 00603d90). Central create-room (op04/op0c) orchestrator. else-opcode identity + 0x10b3 flag not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00603e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
