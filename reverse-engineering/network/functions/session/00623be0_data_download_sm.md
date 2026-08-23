# 0x00623be0 data_download_sm

| field | value |
|---|---|
| Original address | 0x00623be0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623be0 |
| Resolved name | data_download_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00623b10
**Callees:** FUN_0061e730, FUN_0061e860, FUN_0061f0f0, FUN_0061f2d0, FUN_0061f680, FUN_006247c0, FUN_00624800
**Referenced globals:** 0x715298 struct ptr; 0x3433b0/b8 link bits; 0x27e570 status; 0x27e570 err
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x161 dl-state; struct+0x16c msg-id; struct+0x180 result; struct+0x184 timer

## Behavioral explanation
Large scenario/save-data download state machine (struct+0x161 key): polls transfer primitives (func_0x001f5620/4770/4980/4ca0), decodes a rich error space (-0xff..-0xfb), and stages received blocks; sets result at struct+0x180.

## Notes / uncertainty
Struct-based (0x715298) typed content download; subop selector +0x180 (1-6) → libnet 001f4770/4980/4ca0/51b0; result codes → UI msg-ids +0x16c; redraw tail. Poll result→state map summarized, payload types not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623be0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
