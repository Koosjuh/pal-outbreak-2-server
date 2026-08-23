# 0x00622c30 screen_handler_init

| field | value |
|---|---|
| Original address | 0x00622c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00622c30 |
| Resolved name | screen_handler_init |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061ea10, FUN_0061ea20, FUN_0061f8b0, FUN_0061f970
**Referenced globals:** 0x715298 screen struct ptr; 0x66a830 string src
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** substate @ struct+1

## Behavioral explanation
Screen-0 (entry) handler: 3-step init that clears the screen struct, sets up a name/string field, tears down (ea10/ea20), and calls stub f8b0; returns 1 when done.

## Notes / uncertainty
Substate-0 (0/1/2) init of the 0x715298 screen struct: arm -> wait net_conn_teardown_if_ready -> build (reset flag bytes, install default name from 0x66a830 into +0x88 if empty, ea10/ea20/f8b0), return 1. Individual flag-byte roles and f8b0 body not pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00622c30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
