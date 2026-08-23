# 0x005fe300 build_arealist_model

| field | value |
|---|---|
| Original address | 0x005fe300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe300 |
| Resolved name | build_arealist_model |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f91f0, FUN_005fa190, FUN_0062d4e0
**Callees:** FUN_005baf20, FUN_005baf70
**Referenced globals:** 0x341ac8/0x341ad0 sub-scenario masks; 0x3c4d50 id table; 0x6c45f8 profile idx; +0x1a entry array (stride 4); +10 entry count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds the area-select entry list at param+0x1a from availability bitmasks and id tables (areas + their sub-scenarios), writing entry count to +10.

## Notes / uncertainty
Two-pass area-select model builder: pass1 = 8 story areas + up to 4 sub-scenarios each (masks 0x341ac8), pass2 = 128 flat scenarios gated by static mask 0x341ad0 + dynamic availability (FUN_005baf70), from descriptor table 0x3c4d50 stride 0xc; count->+0xa, entries stride4 @+0x1a. Mask table contents not dumped; greyed-vs-selectable mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
