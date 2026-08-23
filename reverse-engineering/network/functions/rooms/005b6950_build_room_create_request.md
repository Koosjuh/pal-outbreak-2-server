# 0x005b6950 build_room_create_request

| field | value |
|---|---|
| Original address | 0x005b6950 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6950 |
| Resolved name | build_room_create_request |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b25c0
**Callees:** FUN_005bdd60
**Referenced globals:** 0x874f9c/33/37/38/3a/3b/35/d8/d9 (user/config fields); 0x874fa0 (name); 0x874fc0 (handle-compare); 0x3c4d50 (id-map table, 0xc stride); bRam00337de1/cRam00337e05 (mode/state flags); 0x354230/354220/354224/343390 (misc config)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00874f35; bRam00337de1; cRam00337e05

## Behavioral explanation
Assemble a room create/register request struct (param_1) from local user/config (0x874f* handle, name 0x874fa0, options), scan up to 4 local character slots resolving names vs 0x874fc0, set counts/flags at param_1+8..+0xc and per-entry rows, then submit via FUN_005bdd60.

## Notes / uncertainty
Assembles 0x9c-byte create-room request from 0x874f* user block + 4 char slots (remap via 0x3c4d50, 999-terminated), submits via FUN_005bdd60; sets valid flag screen+0x439 when create mode 0x874f35==3 and eligibility passes. Struct field names are structural inference.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6950.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
