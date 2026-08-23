# 0x00622f40 screen_handler_data

| field | value |
|---|---|
| Original address | 0x00622f40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00622f40 |
| Resolved name | screen_handler_data |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061ea10, FUN_0061f0d0, FUN_0061f4b0, FUN_00623a40, FUN_00623b10
**Referenced globals:** 0x715298 screen struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** substate @ struct+1; struct+0x180 result; struct+0x16c msg-id

## Behavioral explanation
Screen handler that draws element 0x38 and drives the data sub-machine FUN_00623b10; returns 1 on success / -1 on failure (struct+0x180 result).

## Notes / uncertainty
Data-transfer screen: draws header elem 0x38, two-level timed SM (+4 pre-delay,+6 settle) that calls xfer_buffers_init(0) then pumps data_download_driver; on finish result = (struct+0x180==0)?1:-1; draws status elem struct+0x16c. Transferred payload identity and f4b0 element/string ids unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00622f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
