# 0x005bf830 room_stat_reply_accumulate

| field | value |
|---|---|
| Original address | 0x005bf830 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf830 |
| Resolved name | room_stat_reply_accumulate |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf1e0, FUN_005c7d00
**Referenced globals:** 0x7006b0 slot accum buf; 0x6ce5e0 per-room count (stride 0x144); 0x6cbc1c slot idx; 0x6cbc35 step-ack
**Referenced strings:** ' (0x27) error tag
**Referenced opcodes:** —
**State vars:** 0x6cbc35

## Behavioral explanation
Reply handler for the DIOL/STAT send: iterates reply entry list (count@+8, stride 0x28) accumulating per-slot totals into 0x7006b0 and per-room render count 0x6ce5e0; advances SM when done.

## Notes / uncertainty
STAT reply cb: accumulates entry+0x14 (stride 0x28) into per-slot 0x7006b0 and per-room s16 0x6ce5e0 (stride 0x144); SM flag 0x6cbc35=1/2. Feeds header/roster count (1/0p relevant). Accumulated-field meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf830.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
