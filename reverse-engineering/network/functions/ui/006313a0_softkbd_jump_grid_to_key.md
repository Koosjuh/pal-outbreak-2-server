# 0x006313a0 softkbd_jump_grid_to_key

| field | value |
|---|---|
| Original address | 0x006313a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006313a0 |
| Resolved name | softkbd_jump_grid_to_key |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006314a0
**Callees:** FUN_00630c50, FUN_006322c0, FUN_00635ab0, FUN_00637260, FUN_00637540
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x24 grid col; +0x25 grid row; +0x4a flags; +0x248 result code

## Behavioral explanation
Special key handler: sets grid cursor col/row (+0x24/+0x25) from a computed value and refreshes, else posts result 5.

## Notes / uncertainty
Renamed from reset_grid_position. Special jump key: selects layout index 5, jumps grid cursor to col=((key-0x3a)*5)%20,row=/20. Key arrives via register (extraout_a0_lo decompiler artifact) - liveness not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006313a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
