# 0x005fede0 room_detail_screen_sm

| field | value |
|---|---|
| Original address | 0x005fede0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fede0 |
| Resolved name | room_detail_screen_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005c0f60, FUN_005c4580, FUN_005f4b80, FUN_005f4be0, FUN_005ff1b0, FUN_00600b60, FUN_00601760, FUN_006018d0, FUN_00602700
**Referenced globals:** iRam003435d4 runtime-base (0xcf5c0 stats, 0xc942c slots)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x908 selected member slot; param_1+0x907 cursor; param_1+0x44c active-slot; param_1+0x11 room-variant; param_1+0x992 busy

## Behavioral explanation
In-room detail screen state-machine (cases 0-5): builds the option menu (FUN_00601760/006018d0), runs cursor nav (FUN_005ff1b0), renders roster (FUN_00602700), and copies the selected member block (0x908 slot) into the display buffers.

## Notes / uncertainty
6-case in-room detail SM. Variant fork (+0x11) picks menu builder + input path; mirrors selected member (0x3b0 stride, +0x908) into stats (0xd4@cf5c0) and display row (0x3cdc); variant-B paging behind L1 guards 0x80/0x40. Flag meanings (443/454/9cc) and paging op inferred; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fede0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
