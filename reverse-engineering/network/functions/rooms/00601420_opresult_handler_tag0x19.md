# 0x00601420 opresult_handler_tag0x19

| field | value |
|---|---|
| Original address | 0x00601420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601420 |
| Resolved name | opresult_handler_tag0x19 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b9110, FUN_005f8b50
**Referenced globals:** 0x6c4fbb pending-op tag; 0x6c4b9e/9f/a0/a1 page cursor
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb op tag

## Behavioral explanation
Deferred op-result handler gated on pending-op tag 0x19: on success calls FUN_005f8b50(playerIdx); on failure resets the 6c4b9e paging state and re-arms timer.

## Notes / uncertainty
Deferred op-result cb gated on pending_tag(0x6c4fbb)==0x19; success->FUN_005f8b50(idx) commit, fail->reset SM page0 + msg 0x4c. Concrete lobby action for tag 0x19 not correlated to wire.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
