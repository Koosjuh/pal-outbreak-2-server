# 0x005ff8d0 menu_ctx_init_mode0xc

| field | value |
|---|---|
| Original address | 0x005ff8d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff8d0 |
| Resolved name | menu_ctx_init_mode0xc |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3790
**Callees:** FUN_005aec20, FUN_005f4b70
**Referenced globals:** 0x6c4b90 menu-context mode; 0x6c4fe4/6/8 paging flags; 0x6c4fca flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 context-mode

## Behavioral explanation
Initializes the global menu context at 0x6c4b90 to mode 0xc and clears its 6c4fxx paging/selection flags via FUN_005aec20.

## Notes / uncertainty
Straight-line initializer: sets lobby_state_block screen_id 0x6c4b90=0xc, zeroes SM sub-fields, primes 0x6c4fe4/e6/e8 paging. Paging-field roles inferred from sibling inits.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
