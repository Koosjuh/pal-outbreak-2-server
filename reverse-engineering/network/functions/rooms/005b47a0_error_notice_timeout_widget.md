# 0x005b47a0 error_notice_timeout_widget

| field | value |
|---|---|
| Original address | 0x005b47a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b47a0 |
| Resolved name | error_notice_timeout_widget |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3ed0, FUN_005b41b0
**Callees:** FUN_005b4c80, FUN_005b9110, FUN_005ba570
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget+3 sub-state; widget+0x18 timer

## Behavioral explanation
Sub-widget: 3-phase countdown that shows an error/retry panel (0x5b4c80(6), 0x5b9110(0x4c)) and returns done after ~0x3c ticks.

## Notes / uncertainty
Renamed retry_timeout_widget->error_notice_timeout_widget. Pure 3-phase time-driven (0x3c-tick dwells) panel+message-box(0x4c) display, no input/network. Used by enter/create on failure. Uncertainty: distinct text per phase not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b47a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
