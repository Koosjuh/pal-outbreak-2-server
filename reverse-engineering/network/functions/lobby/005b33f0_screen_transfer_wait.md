# 0x005b33f0 screen_transfer_wait

| field | value |
|---|---|
| Original address | 0x005b33f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b33f0 |
| Resolved name | screen_transfer_wait |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005b14b0, FUN_005b9060, FUN_005ba7b0, FUN_00618b60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x16 timer; struct+0x5ec request buffer

## Behavioral explanation
Screen-4 short wait/transfer state: 300-tick countdown +0x16, sends a request via 0x5b9060(0,+0x5ec) then advances to screen 3.

## Notes / uncertainty
3-phase screen SM on +0x0f: init(arm 300-tick timer, send request via FUN_005b9060 into +0x5ec), wait(countdown, early confirm past 0xf0 debounce on input 0x10), commit(poll FUN_005af310 -> FUN_00618b60, screen_id=3 roomlist). 0xf0 debounce and emitted opcode inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b33f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
