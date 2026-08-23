# 0x006293f0 room_password_entry_sm

| field | value |
|---|---|
| Original address | 0x006293f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006293f0 |
| Resolved name | room_password_entry_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_005af440, FUN_005b0cd0, FUN_005b1420, FUN_005b1460, FUN_005b14b0, FUN_005b8cf0, FUN_005b8da0, FUN_005b9110, FUN_00604860
**Referenced globals:** 0x870880 pw/room-table(0x1e); param+0xefb key-input; param+0x90b flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Password/keyboard sub-machine (cases 0-7): looks up an entry in table 0x870880 (FUN_00604860), shows the input dialog via FUN_005b8da0/8cf0, validates (FUN_005af440), and times the retry/close windows.

## Notes / uncertainty
All 8 sub-cases preserved; password table 0x870880 stride 0x1e; dialog ids 0x5d/0x5e/99 inferred; pad-test polarity inferred. No opcode emitted directly.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006293f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
