# 0x005d89d0 ui_set_status_message_timed

| field | value |
|---|---|
| Original address | 0x005d89d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d89d0 |
| Resolved name | ui_set_status_message_timed |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e9f80
**Callees:** —
**Referenced globals:** 0x00701070 UI widget base; 0x00069014 timeout field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a string into the overlay widget's status buffer (iRam00701070+0x3b) and sets a display timeout of param*0x1e (frames), default 0x1e.

## Notes / uncertainty
Status line at UI base(0x701070)+0x3b; timeout at draw-ctx(0x701068)+0x69014 = units*0x1e frames, 0-guard→0x1e. 0x1e-as-one-second and base-global roles inferred, not PINE-traced. Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d89d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
