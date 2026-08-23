# 0x005ac3b0 clear_menu_state_874f30

| field | value |
|---|---|
| Original address | 0x005ac3b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac3b0 |
| Resolved name | clear_menu_state_874f30 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac6f0, FUN_005f3e30
**Callees:** —
**Referenced globals:** 0x874f30(menu state blk,0xAC); 0x870868(flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00870868

## Behavioral explanation
Zeroes a 0xAC-byte menu-state block at 0x874f30 and clears flag 0x870868.

## Notes / uncertainty
memset(0x874f30,0,0xAC) secondary menu block + clear flag 0x870868, on warm re-entry. Internal layout of the 0xAC block not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac3b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
