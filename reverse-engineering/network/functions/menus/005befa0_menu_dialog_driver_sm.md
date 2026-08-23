# 0x005befa0 menu_dialog_driver_sm

| field | value |
|---|---|
| Original address | 0x005befa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005befa0 |
| Resolved name | menu_dialog_driver_sm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005beb40, FUN_005bebf0
**Referenced globals:** 0x6cbaf4 enable flag; 0x6cbaf0 state cursor; 0x6cbaf5 result byte; 0x6cbad4 completion cb ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbaf4 enable; 0x6cbaf0 state; 0x6cbaf5 result

## Behavioral explanation
6-state driver (gated on enable cRam006cbaf4) that runs the menu build (FUN_005beb40/FUN_005bebf0) then fires completion callback pcRam006cbad4 with 0x00/0xff result.

## Notes / uncertainty
6-state two-pass dialog pump (enable 0x6cbaf4, step 0x6cbaf0, result 0x6cbaf5); builds via beb40 then bebf0, fires cb 0x6cbad4 with 0x00/0xFF. No caller in slice (frame-pumped); build-pass meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005befa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
