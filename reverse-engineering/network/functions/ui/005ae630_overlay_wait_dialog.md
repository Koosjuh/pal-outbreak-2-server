# 0x005ae630 overlay_wait_dialog

| field | value |
|---|---|
| Original address | 0x005ae630 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae630 |
| Resolved name | overlay_wait_dialog |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae3e0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b14b0, FUN_005b9110, FUN_005c4460, FUN_0062fea0
**Referenced globals:** obj +0x54b5/+0x54ba/+0x54bc
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay state 1 of 54b4: shows a centered message (string via FUN_0062fea0(0xd), width-centered draw) and waits on pad (5b14b0 0x10) / countdown before advancing.

## Notes / uncertainty
Phase-1 of 54b4: centered 'wait' notice (loc string 0xd, x=0x140-w/2,y=0x160), confirm mask 0x10, 6-frame auto-dismiss, sets ack +0x54bc, teardown FUN_005c4460. Font-width scaling idiom approximated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
