# 0x005ecf20 layout_hrule_element

| field | value |
|---|---|
| Original address | 0x005ecf20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ecf20 |
| Resolved name | layout_hrule_element |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e99c0
**Callees:** FUN_005d9890, FUN_005eced0, FUN_005ef780
**Referenced globals:** iRam007012a0; +0x188 (line idx); +0xd892 (depth); +0x186 (pass)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd892

## Behavioral explanation
Lays out an <hr>-like rule element: computes x/y from margins and element metrics (branching on block-stack depth +0xd892) then draws via FUN_005d9890.

## Notes / uncertainty
<hr> position+draw on render pass; forks on nesting depth +0xd892 (top-level margins+center vs table-cell record stride 0x5c). Cell record fields & FUN_005ef780 role partially decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ecf20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
