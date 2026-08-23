# 0x006088b0 reconnect_state_machine

| field | value |
|---|---|
| Original address | 0x006088b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006088b0 |
| Resolved name | reconnect_state_machine |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_001b3720, FUN_005ac380, FUN_005ac6f0, FUN_005af340, FUN_005c80a0, FUN_005c8810, FUN_005cd710, FUN_005de2a0, FUN_00606a70, FUN_00606ac0, FUN_00606c80, FUN_00618b60
**Referenced globals:** 0x0070cd98 state; 0x003c8a80 conn-mode; 0x00701e20 req-buf; 0x0070cd80 status; 0x006c4fd7 flag; 0x0064a110 fmt
**Referenced strings:** 0x64a110 (fmt)
**Referenced opcodes:** —
**State vars:** cRam0070cd98; uRam003c8a80

## Behavioral explanation
Connect/reconnect state machine on cRam0070cd98 (0-4): sprintf request into 0x701e20, connect/poll (005c80a0/005c8810), branches on results, on failure sets status 0070cd80=0x85 and returns via FUN_00606ac0.

## Notes / uncertainty
Stripped-down background reconnect variant of 00608300; always default template 0x64a110, no msg widgets; on success FUN_005cd710 session-check gates finalize. Check semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006088b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
