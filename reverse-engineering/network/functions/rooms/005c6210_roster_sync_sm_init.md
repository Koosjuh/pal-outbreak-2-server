# 0x005c6210 roster_sync_sm_init

| field | value |
|---|---|
| Original address | 0x005c6210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6210 |
| Resolved name | roster_sync_sm_init |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616d30, FUN_006173c0
**Callees:** —
**Referenced globals:** 0x6ff2bd candidate-tbl(0x114*4); 0x6cbb94 sm-active; 0x6cbb70 pump-fnptr; 0x6cbb90 sm-phase; 0x6cbb74 done-cb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbb94 sm-active

## Behavioral explanation
Initializes the room-roster sync state machine: seeds a 4-entry candidate table at 0x6ff2bd from stack args and registers FUN_005c6500 as the pump callback.

## Notes / uncertainty
Arms roster-sync SM: seeds 4-slot candidate table 0x6ff2bd (0x114 stride), installs FUN_005c6500 pump, phase=0, done-cb=param_2; single-shot guard 0x6cbb94 (ret -1 if active). Per-slot source addressing over-runs 48-byte staged buf (Ghidra artifact).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
