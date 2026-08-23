# 0x005cf1e0 room_exit_input_handler

| field | value |
|---|---|
| Original address | 0x005cf1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cf1e0 |
| Resolved name | room_exit_input_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5b60, FUN_005d5c20, FUN_0061e730
**Referenced globals:** 0x701068+0x68e85 phase; 0x701068+0x5ffc0 display-list; 0x3c8a80 link state; 0x701068+0x60dca flag; 0x701f20 gate; 0x701e18 result sel; 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** 0x0b
**State vars:** 0x701068+0x68e85; 0x3c8a80; 0x701070+0x2e

## Behavioral explanation
Sets phase 0x68e85=0xb and, on confirm pad, either counts pending room ('\r' state1) rows and re-sends op0b (FUN_005d5c20(0xb)) or pops the screen; branches on cRam003c8a80 (connection/link state).

## Notes / uncertainty
Exit/leave-confirm (phase 0xb): on confirm, link-up in-room -> literal infinite-loop hang guard; link-down host path re-issues op0b if queried rooms pending else pops with cancel result 0xFF. op0b wire meaning not in confirmed opcode table.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cf1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
