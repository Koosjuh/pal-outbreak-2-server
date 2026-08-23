# 0x0062aeb0 room_enter_menu

| field | value |
|---|---|
| Original address | 0x0062aeb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062aeb0 |
| Resolved name | room_enter_menu |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062a5e0
**Callees:** FUN_00618b60, FUN_00629d00, FUN_0062b670, FUN_0062cf50
**Referenced globals:** 0x7154a0 enter-scratch; 0x7154b1 name-scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007154b1

## Behavioral explanation
Enter handler that first drives the network enter submachine (FUN_0062cf50 @0x7154a0); on success builds widgets and dedups name scratch across the 3 slots.

## Notes / uncertainty
Enter-menu gated on FUN_0062cf50 enter submachine; 3-slot name de-dup into 0x7154b1. Decompiler-mangled loop index (iVar2 recurrence) means per-iteration slot address uncertain; 0x25 stride reliable from post-loop term.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062aeb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
