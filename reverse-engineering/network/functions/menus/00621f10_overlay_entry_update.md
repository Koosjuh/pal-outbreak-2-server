# 0x00621f10 overlay_entry_update

| field | value |
|---|---|
| Original address | 0x00621f10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00621f10 |
| Resolved name | overlay_entry_update |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3f50, FUN_005f41e0
**Callees:** FUN_0061e9c0, FUN_00621ed0, FUN_00622180
**Referenced globals:** 0x715298 struct ptr; 0x7153e8 lifecycle phase; 0x7152e0 struct base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007153e8; iRam00715298

## Behavioral explanation
Overlay lifecycle entry: sets struct ptr (0x7152e0) then init(0)/update(1 -> run dispatcher FUN_00622180)/shutdown(2) based on phase iRam007153e8.

## Notes / uncertainty
Already a full reconstruction (3-way overlay phase branch, ctx+0x108 counter). Left in place; meaning of ctx+0x108 (frame tally vs anim tick) still runtime-unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00621f10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
