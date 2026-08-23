# 0x00601700 opresult_handler_tag0x22

| field | value |
|---|---|
| Original address | 0x00601700 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601700 |
| Resolved name | opresult_handler_tag0x22 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005acda0, FUN_005f4b70
**Referenced globals:** 0x6c4fbb pending-op tag; 0x6c4b90 menu context; 0x874fd4 arg
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb op tag

## Behavioral explanation
Deferred op-result handler gated on pending-op tag 0x22: commits the menu-context transition via FUN_005acda0(0x6c4b90,...) and refreshes.

## Notes / uncertainty
Deferred one-shot handler gated on screen_id!=6 && pending_tag==0x22; commits transition via FUN_005acda0(0x6c4b90,0x874fd4). Direct producer link to 0x00600d10. Transition-arg 0x874fd4 contents undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601700.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
