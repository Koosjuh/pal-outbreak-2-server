# 0x005bdfe0 dispatch_by_mode

| field | value |
|---|---|
| Original address | 0x005bdfe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdfe0 |
| Resolved name | dispatch_by_mode |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bb4d0, FUN_005bb670, FUN_005bb8e0, FUN_005bb980, FUN_005bbb90, FUN_005bbc20, FUN_005bbe00, FUN_005bbea0, FUN_005bc430, FUN_005bd8c0, FUN_005bfb40, FUN_005bfe90, FUN_005c0060, FUN_005c05c0, FUN_005c0ae0, FUN_005c21c0, FUN_005c2460, FUN_005c29c0, FUN_005c3490, FUN_005c44a0, FUN_005c5a10, FUN_005c70e0, FUN_005c7420, FUN_005c76e0
**Callees:** FUN_005bdf90, FUN_005be120, FUN_005be9d0
**Referenced globals:** 0x6cbc7e mode selector; 0x6cbc84 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc7e dispatch-mode; 0x6cbc84 active flag

## Behavioral explanation
Mode-selected dispatch on sRam006cbc7e: mode 0x10 forwards to menu-event dispatch; mode 2 emits a 1-byte {0/0xff} record via FUN_005be120 (slot free/notify).

## Notes / uncertainty
24-caller UI event router on mode 0x6cbc7e: mode0x10(roster panel)->menu dispatch 005bdf90; mode2(confirm)->enqueue 1-byte reply 0x00/0xff (005be120) keyed on flag 0x6cbc84. Ack-encoding 0x00/0xff inferred, not wire-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdfe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
