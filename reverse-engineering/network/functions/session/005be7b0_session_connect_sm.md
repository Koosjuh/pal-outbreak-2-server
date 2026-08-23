# 0x005be7b0 session_connect_sm

| field | value |
|---|---|
| Original address | 0x005be7b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be7b0 |
| Resolved name | session_connect_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x6cbbe4 active; 0x6cbbe0 phase; 0x6cbbc4 completion cb; 0x6ce5c8 lobby buf; 0x70047c flag; 0x6ff2b1 scenario lock; 0x35b9e0 handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbbe0 connect phase (0-3); 0x6ff2b1 scenario lock (cleared on connect)

## Behavioral explanation
Session connect/disconnect state machine (phases 0->1->2->3 in cRam006cbbe0): advances the handshake, on phase2 clears lobby buffers (0x6ce5c8, 0x70047c, 0x6ff2b1) and fires the completion callback; phase3 signals error (0xff).

## Notes / uncertainty
Lifecycle SM (phase 0x6cbbe0 0->1->2, 3=error). phase1 closes prior transport; phase2 success (clears 0x6ce5c8/0x70047c/0x6ff2b1, cb 0x00); phase3 cb 0xff. Note: RESETS unlock_gate 0x6ff2b1 every connect (G12 lifecycle). Error-entry into phase3 not shown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be7b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
