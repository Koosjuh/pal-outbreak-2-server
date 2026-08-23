# 0x00618ba0 sprite_slot_alloc

| field | value |
|---|---|
| Original address | 0x00618ba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618ba0 |
| Resolved name | sprite_slot_alloc |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af4d0, FUN_005af840, FUN_005b1d20, FUN_005b6c90, FUN_005b6cf0, FUN_005b8130, FUN_005b8cf0, FUN_005b8e40, FUN_005b8f60, FUN_005b9060, FUN_005ba570, FUN_005ba7c0, FUN_005ba940, FUN_005f58c0, FUN_005f62e0, FUN_005f8340, FUN_005fba80, FUN_005fc850, FUN_00601760, FUN_006018d0, FUN_006020e0, FUN_00602230, FUN_00604af0, FUN_006053e0, FUN_00607f70, FUN_00608090, FUN_00628760, FUN_00629a40, FUN_00629d00, FUN_0062b670, FUN_0062cd20, FUN_0062f500, FUN_0062f890
**Callees:** —
**Referenced globals:** 0x7133f0 sprite table (64 x 0x54)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates the first free entry from a 64-slot sprite table (base 0x7133f0, stride 0x54), marks it used and seeds default fields.

## Notes / uncertainty
First-free allocator over 64-slot sprite table @0x7133f0 stride 0x54; marks used, seeds color(+0x2c)=white, tex(+0x34)=-58; NULL when full. Corrected the record's field offsets (raw writes 0x71341c/0x713424 = +0x2c/+0x34, not +0x1c/+0x24).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618ba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
