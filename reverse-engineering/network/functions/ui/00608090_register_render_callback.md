# 0x00608090 register_render_callback

| field | value |
|---|---|
| Original address | 0x00608090 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608090 |
| Resolved name | register_render_callback |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607ac0
**Callees:** FUN_00618ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a render node (FUN_00618ba0) and installs FUN_006080d0 as its draw callback (+0xc).

## Notes / uncertainty
Allocates a render-hook node (enabled=0) installing FUN_006080d0 draw cb (room-detail renderer). What FUN_006080d0 renders not deep-read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608090.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
