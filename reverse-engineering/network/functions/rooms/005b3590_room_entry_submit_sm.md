# 0x005b3590 room_entry_submit_sm

| field | value |
|---|---|
| Original address | 0x005b3590 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3590 |
| Resolved name | room_entry_submit_sm |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005b3b70, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005ba7b0, FUN_005bdb00, FUN_005bdc30, FUN_0062fea0
**Referenced globals:** 0x874f35 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x4092 buffer; struct+0x4096 buffer; struct+0x16 timer

## Behavioral explanation
Screen-6 machine gated by 0x5b3b70(mode): builds a panel (0x5bdb00/dc30) around buffer +0x4092/+0x4096 and submits via 0x5b9060(0x14).

## Notes / uncertainty
RENAMED from misleading 'screen_state6_entry' — it is a full 0..7 state machine (with explicit 6->7 fallthrough), not a state-6 entry. Value-entry (+0x4092) -> validate (FUN_005b3b70) -> reliable submit selector 0x14 (buf +0x4096) -> poll result -> centered status text. Uncertainty: exact op (join-by-code/password) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
