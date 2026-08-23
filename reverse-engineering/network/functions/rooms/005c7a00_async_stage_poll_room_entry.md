# 0x005c7a00 async_stage_poll_room_entry

| field | value |
|---|---|
| Original address | 0x005c7a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7a00 |
| Resolved name | async_stage_poll_room_entry |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00606fc0, FUN_00607370
**Callees:** FUN_005c7ae0
**Referenced globals:** 0x86f800 (selected index); 0x700fd8 (stage flag); 0x365e20 (room table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x700fd8

## Behavioral explanation
Async ladder that indexes the room table (0x365e20, stride 0x260) by selected index and drives sub-stage FUN_005c7ae0 to completion.

## Notes / uncertainty
3-stage polled ladder (0x700fd8) resolving selected room detail via FUN_005c7ae0 over 0x365e20 table; returns 1=done/0=pending/-1=error. Sub-stage 7ae0 body not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
