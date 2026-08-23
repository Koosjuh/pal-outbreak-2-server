# 0x005e0270 texture_set_load_for_mode

| field | value |
|---|---|
| Original address | 0x005e0270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0270 |
| Resolved name | texture_set_load_for_mode |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005e0140
**Referenced globals:** 0x646630/0x646660/0x646690 (texture source blobs)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads a specific set of UI textures (from source addrs 0x646630/60/90) depending on mode arg (3 or 4).

## Notes / uncertainty
Bulk-loads UI texture set: mode 4 -> 2 blobs (0x646660, 0x646690 via func_0x001cf2b0), mode 3 -> 1 blob (0x646630), all variant 0. Meaning of modes 3/4 depends on caller FUN_005cd320; func_0x001cf2b0 semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
