# 0x006139c0 player_entry_render

| field | value |
|---|---|
| Original address | 0x006139c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006139c0 |
| Resolved name | player_entry_render |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_0060f8b0, FUN_006146e0, FUN_00614720, FUN_00614870
**Referenced globals:** fmt 0x654148 ('#N name'); 0x653f70 (name-ctx table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Renders one player-slot entry: resolves the member name (extraout a0 from prior FUN_0060e1c0) or a default (ctx tbl+0x28), formats '#N name' (fmt 0x654148) and draws at (param3,param4).

## Notes / uncertainty
Draws '#N name' player line; empty slot -> dim color 0x80000080 + placeholder name (ctx+0x28), occupied -> live name via FUN_00614870. Member handle/name from Ghidra extraout regs of FUN_0060f8b0, so name-source binding and '#%d %s' fmt are inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006139c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
