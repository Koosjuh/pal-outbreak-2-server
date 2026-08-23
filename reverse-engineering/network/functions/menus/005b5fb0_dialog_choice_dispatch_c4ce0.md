# 0x005b5fb0 dialog_choice_dispatch_c4ce0

| field | value |
|---|---|
| Original address | 0x005b5fb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5fb0 |
| Resolved name | dialog_choice_dispatch_c4ce0 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c4ce0, FUN_006000e0
**Referenced globals:** cRam006c4b90 (mode); uRam006c5539 (dialog result byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; uRam006c5539

## Behavioral explanation
If mode!=6: read a dialog result struct (FUN_005c4ce0); result 0 stores a byte to uRam006c5539; result 1 in mode 0x0c invokes FUN_006000e0.

## Notes / uncertainty
Modal result router (skip screen 6): polls result via 0x5c4ce0; code 0 stores choice byte to 0x6c5539; code 1 on screen 0x0c (leave/exit-room dialog) calls 0x6000e0 (room-leave, likely emits SN@P 0x07/0x08). Routing/offsets exact; full result struct + leave action inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5fb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
