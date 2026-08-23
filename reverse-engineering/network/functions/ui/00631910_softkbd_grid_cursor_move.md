# 0x00631910 softkbd_grid_cursor_move

| field | value |
|---|---|
| Original address | 0x00631910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631910 |
| Resolved name | softkbd_grid_cursor_move |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631ac0, FUN_00631bb0, FUN_00631c80, FUN_00631cf0
**Callees:** FUN_00634470
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x24 grid col; +0x25 grid row; +0x2e layout counter; +0x248 result code

## Behavioral explanation
Moves the on-screen key-grid cursor by direction 0-3: wraps col (+0x24, 1..20) and clamps row (+0x25, 0..3), skipping empty cells via layout refresh.

## Notes / uncertainty
D-pad grid move (dir 0-3): col wraps 1..20, row clamps 0..3; do/while loops until cell token +0x2e changes to skip wide-key spans; result 0 (nav). FUN_00634470 token derivation not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631910.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
