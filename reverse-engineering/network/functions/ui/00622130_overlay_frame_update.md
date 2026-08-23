# 0x00622130 overlay_frame_update

| field | value |
|---|---|
| Original address | 0x00622130 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00622130 |
| Resolved name | overlay_frame_update |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00619800, FUN_0061e8f0, FUN_00621fe0
**Referenced globals:** 0x715298 screen struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00715298

## Behavioral explanation
Per-frame overlay tick: runs bg scroll anim (if struct+0x15c set) and the input/update sub (thunk_FUN_00619800) unless struct+0xe bit1 set.

## Notes / uncertainty
Per-frame callback (registered as 0x622130 by wait_reply): runs bg anim if obj+0x15c, input tick FUN_00619800 unless obj+0xe bit1 set. FUN_00619800 internals not read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00622130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
