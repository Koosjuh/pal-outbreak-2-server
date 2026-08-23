# 0x005ff830 screen_reset_to_menu8

| field | value |
|---|---|
| Original address | 0x005ff830 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff830 |
| Resolved name | screen_reset_to_menu8 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aec70, FUN_005ff690
**Callees:** FUN_005aec20, FUN_005b1d10, FUN_005f4b70, FUN_00637180
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xf=8; param_1+0x10; param_1+0x443 mode; param_1+0x43d=0x4c screen-id; param_1+0x45d=2

## Behavioral explanation
Hard-resets the screen struct to menu step 8/sub-2 (or 8/0 with mode 0x443=1 when param2!=0), re-inits sub-systems (FUN_005aec20/005b1d10/00637180) and sets screen-id 0x4c.

## Notes / uncertainty
Back/abort reset of the overlay screen SM to major-state 8; param_2 selects fresh(step2) vs return(step0, sets +0x443 flag). +0x443/+0x45d byte-flag semantics inferred, not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff830.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
