# 0x00606ea0 init_record_buffers3

| field | value |
|---|---|
| Original address | 0x00606ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606ea0 |
| Resolved name | init_record_buffers3 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_00606e40
**Callees:** —
**Referenced globals:** 0x003435d4 scratch-base; 0x006c5480 buf-ptr[3]
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes 0x8000 scratch at [3435d4] and installs three 0x17bb-aligned buffer pointers at 0x6c5480.

## Notes / uncertainty
Zeroes 0x8000 scratch at 0x3435d4, publishes 3 record-buffer bases at 0x6c5480 spaced 0x17bb 0x40-aligned. Which buffer backs which drawn table not resolved here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
