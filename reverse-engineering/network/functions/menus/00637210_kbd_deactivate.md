# 0x00637210 kbd_deactivate

| field | value |
|---|---|
| Original address | 0x00637210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637210 |
| Resolved name | kbd_deactivate |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0, FUN_006345e0, FUN_00637180
**Callees:** —
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x30 active; 0x26 confirm

## Behavioral explanation
Setter: deactivates the keyboard (0x30=0) and sets confirm flag (0x26=1) — the 'leave text entry' state change.

## Notes / uncertainty
Close transition: active +0x30=0, confirm +0x26=1. Inverse of 6371f0; used by dismiss path 637180.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
