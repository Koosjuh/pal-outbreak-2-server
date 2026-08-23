# 0x0062b2c0 msgbox_build_1d

| field | value |
|---|---|
| Original address | 0x0062b2c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062b2c0 |
| Resolved name | msgbox_build_1d |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_0062b500, FUN_0062fea0
**Referenced globals:** 0x6c4b90 mode; 0x6c4fbb trigger-state; 0x6c5ff0 sel idx; 0x6c5bd5/0x6c5be5 member fields; 0x6c517c dest buf; 0x66ad80/0x66ad98/0x66ada8 fmt
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c4b90

## Behavioral explanation
Builds a room-info/message string (triggered by cRam006c4fbb==0x1d) from localized fragments and the selected member record, feeding a marquee/scroll display.

## Notes / uncertainty
One-shot msgbox text builder gated on screen!=6 && pending_tag(0x6c4fbb)==0x1d (consumes tag). Formats selected member record (0x25 stride @0x6c5bd5/detail @0x6c5be5) with localized fragments; marquee vs plain by param_1[0]; msg-kind 0x6c5c44; dest 0x6c517c. Member field layout partially decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062b2c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
