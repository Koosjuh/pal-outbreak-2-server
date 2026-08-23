# 0x00627b00 roster_selection_confirm_sm

| field | value |
|---|---|
| Original address | 0x00627b00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627b00 |
| Resolved name | roster_selection_confirm_sm |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627f20, FUN_0062d1b0
**Callees:** FUN_005b68e0, FUN_005c4380
**Referenced globals:** 0x715512 slot-timer; 0x715511 slot-status; 0x7154f0 selected-slot; 0x6c4fbb req-tag; 0x6c5c44 reply-code
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007154c8 confirm-phase; cRam006c5c44 reply; cRam006c4fdf pending

## Behavioral explanation
State machine (cRam007154c8 0->1->2) that, after a confirm reply (cRam006c5c44), writes highlight/status code into the selected roster slot at 0x715511/0x715512.

## Notes / uncertainty
3-phase member-action confirm SM: issues request (tag 0x24, timeout 0x708), registers reply cb 0x627c90, stamps display row status(1/2/3)+timer 0x1518 on reply. Status-code meanings inferred; the app opcode behind FUN_005b68e0 not identified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627b00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
