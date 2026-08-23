# 0x005bc1c0 inroom_recv_member_text_fragment

| field | value |
|---|---|
| Original address | 0x005bc1c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc1c0 |
| Resolved name | inroom_recv_member_text_fragment |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** —
**Referenced globals:** 0x6fffd1 (per-player chat/text buffer, stride 0x114)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2b1

## Behavioral explanation
Sub-event 7: when in-room, copies a variable-length text blob (len at payload+5) into the per-player chat/text buffer at 0x6fffd1 + slot*0x114 + offset(payload+6).

## Notes / uncertainty
In-room DATA sub-event 7: gated by 0x6ff2b1; memcpy fragment into 0x6fffd1 + slot*0x114 + offset. Stride 0x114 matches relayed member_record. slot@+4,len@+5,offset@+6,data@+8. Chat-text vs charstat-stream disambiguated by dst offset at runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc1c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
