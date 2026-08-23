# 0x005f4e40 chatlog_ring_advance_head

| field | value |
|---|---|
| Original address | 0x005f4e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4e40 |
| Resolved name | chatlog_ring_advance_head |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f50d0
**Callees:** —
**Referenced globals:** iRam003435d4+0xc9358(ring head); +0xc935c(scroll); +0xc9360(tail); cRam006c50fb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xc9358 head; +0xc9360 tail

## Behavioral explanation
Advances the 50-entry chat/message ring-buffer head (wrapping at 0x32), nudging the tail/scroll cursor.

## Notes / uncertainty
50-slot chat ring: head=+0xc9358 write cursor, tail=+0xc9360 oldest, view=+0xc935c scroll anchor. Advances head (mod 50), evicts oldest on full, re-pins view in history mode (cRam006c50fb!=0). Direction convention inferred from caller/renderer; arithmetic exact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
