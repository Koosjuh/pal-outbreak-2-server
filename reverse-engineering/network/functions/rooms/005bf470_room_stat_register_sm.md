# 0x005bf470 room_stat_register_sm

| field | value |
|---|---|
| Original address | 0x005bf470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf470 |
| Resolved name | room_stat_register_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf1e0, FUN_005c3e50
**Referenced globals:** 0x6cbc34 busy; 0x6cbc30 state; 0x6cbc24 room idx; 0x6cbc1c slot counter; 0x6cbc18 count; 0x7006b0 accum buf; 0x6ce49c per-room field; 0x6fec28/0x6fec04 registry A
**Referenced strings:** DIOL (0x4c4f4944); STAT (0x53544154); USER (0x55534552); !
**Referenced opcodes:** —
**State vars:** 0x6cbc30 SM state; 0x6cbc35 step-ack

## Behavioral explanation
State machine that registers the created room: builds DIOL/STAT payloads for up to 4 player slots (loops 0x6cbc1c 0..3) then sends a USER register, via reliable compose+send.

## Notes / uncertainty
6-state create-room commit SM: LOID/STAT TLV loop over 4 slots (compose func_0x001e0ed8+FUN_005c3e50) then op09 reliable USER register (func_0x001dd840, cb 0x5bf740). CORRECTED tag: 0x4c4f4944 is 'LOID' (BE), prior note called it 'DIOL'. STAT-on-op49 and TLV layout need a wire sample.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
