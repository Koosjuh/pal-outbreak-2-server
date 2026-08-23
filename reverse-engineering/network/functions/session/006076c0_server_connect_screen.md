# 0x006076c0 server_connect_screen

| field | value |
|---|---|
| Original address | 0x006076c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006076c0 |
| Resolved name | server_connect_screen |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606cf0
**Callees:** FUN_005ac380, FUN_005af1e0, FUN_005af2c0, FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005af340, FUN_005b24c0, FUN_005b8cf0, FUN_005be8c0, FUN_005be900, FUN_005c80a0, FUN_005c8810, FUN_005de2a0, FUN_00606a50, FUN_00608840, FUN_0062fea0
**Referenced globals:** 0x00701e20 req-buf; 0x003c8a80 conn-mode; 0x00701f20 flag; 0x0070cd80 status
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam003c8a80; uRam00701f20

## Behavioral explanation
State-5 connect screen: 12-step switch driving connect (005c80a0)/poll (005c8810), sprintf request into 0x701e20, animated progress bar (005af1e0), and audio cues by phase.

## Notes / uncertainty
12-step animated connect screen (step at +1); sets conn-mode 0x3c8a80=2, builds request 0x701e20 from 0x8711fd, connect/poll 005c80a0/8810, result message by mode +8 (0x11/0x2a/0x50). Message-id meanings inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006076c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
