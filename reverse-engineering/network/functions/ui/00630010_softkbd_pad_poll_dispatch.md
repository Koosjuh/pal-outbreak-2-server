# 0x00630010 softkbd_pad_poll_dispatch

| field | value |
|---|---|
| Original address | 0x00630010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630010 |
| Resolved name | softkbd_pad_poll_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634ab0
**Callees:** FUN_006300a0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4a3 event byte; +0x4a4 current key code; +0x4a5 previous key code

## Behavioral explanation
Detects a new pad-button edge (+0x4a4 changed) and, if so, sets event code 0x9e and invokes the soft-keyboard key dispatcher.

## Notes / uncertainty
Per-frame edge-triggered front end: rolls +0x4a4/+0x4a5, on key-change edge sets event 0x9e and calls dispatcher 0x6300a0. Other +0x4a3 event bits beyond 0x80/0x9e unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
