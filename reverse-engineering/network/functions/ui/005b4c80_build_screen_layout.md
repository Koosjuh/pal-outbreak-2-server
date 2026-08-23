# 0x005b4c80 build_screen_layout

| field | value |
|---|---|
| Original address | 0x005b4c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b4c80 |
| Resolved name | build_screen_layout |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3cb0, FUN_005b3ed0, FUN_005b41b0, FUN_005b45f0, FUN_005b47a0, FUN_005faa60
**Callees:** FUN_005b8130
**Referenced globals:** 0x638d40 PTR_DAT_00638d40 element-list table A; 0x638e10 PTR_DAT_00638e10 element-list table B; 0x638e40 DAT_00638e40 coordinate table; 0x6c4fcd uRam006c4fcd current-layout id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fcd

## Behavioral explanation
Generic screen-layout builder: for layout index param, walks two PTR-indexed element tables and instantiates each element (0x5b8130), stamping coords from 0x638e40 and screen id +2.

## Notes / uncertainty
Generic UI layout expander: walks two 12-byte-descriptor lists (PTR_0x638d40/0x638e10 indexed by layout), instantiates each element via 0x5b8130, stamps X/Y from coord table 0x638e40, layout id at +2. Table-A failure returns, table-B failure breaks (asymmetry preserved). Non-coord descriptor fields consumed in callee (unresolved).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b4c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
