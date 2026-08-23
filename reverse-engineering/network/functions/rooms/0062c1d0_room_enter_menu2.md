# 0x0062c1d0 room_enter_menu2

| field | value |
|---|---|
| Original address | 0x0062c1d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c1d0 |
| Resolved name | room_enter_menu2 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062ba70
**Callees:** FUN_00618b60, FUN_00629d00, FUN_0062cd20, FUN_0062cf50
**Referenced globals:** 0x7154a0 enter-scratch; 0x7154b1 name-scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007154b1

## Behavioral explanation
Enter handler (screen 3) that drives the network enter submachine (FUN_0062cf50 @0x7154a0), builds widgets and dedups name scratch across the 3 slots; twin of FUN_0062aeb0.

## Notes / uncertainty
Twin of 0062aeb0 (roster-panel variant: phase set before UI, uses FUN_0062cd20+2x FUN_00629d00). Same mangled-loop-index caveat; why two enter variants exist (host vs joiner) not resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c1d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
