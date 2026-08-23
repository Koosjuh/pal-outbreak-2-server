# 0x005aeb10 list_build_from_source

| field | value |
|---|---|
| Original address | 0x005aeb10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aeb10 |
| Resolved name | list_build_from_source |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ae8a0
**Callees:** FUN_00618890
**Referenced globals:** 0x697020 display-list table (0xc/entry); 0x6c5480/0x6c5484 render buffers; 0x697020/28 counts
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads a source list (count+ptr via FUN_00618890), copies its 12-byte-per-entry records into the display table at 0x697020, then memcpy's the assembled buffer into the render buffers.

## Notes / uncertainty
Assembles source records (count+ptr via FUN_00618890, 0xc/entry) into 0x697020, snapshots cur->prev record buffer (0x6c5480->0x6c5484, 0x177c), then memset+reload current from entry0.srcptr. Final load uses only entry0 (surprising - maybe count==1 or concatenated blob); source==roster vs generic list unproven. memcpy/memset arg shapes inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aeb10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
