# 0x00610580 room_join_sm

| field | value |
|---|---|
| Original address | 0x00610580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00610580 |
| Resolved name | room_join_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_001b00e0, FUN_0060e820, FUN_0060e9b0, FUN_0060ef20, FUN_0060f2c0, FUN_006101d0, FUN_006150b0, FUN_006153b0, FUN_006186e0
**Referenced globals:** ctx+0x20 (join sub-state); ctx+0x600 (resolved-room record); ctx+0x25c/0x268 (slot/addr); uRam003433b0 (input); ctx+0x1aec4 (timeout ctr); 0x3ca2d0/0x3c98b0 (register/resolve templates)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x20 join state; uRam003433b0 input bits; ctx+0x1aec4 countdown

## Behavioral explanation
Join-room state machine (switch ctx+0x20): registers user (FUN_0060e9b0,0x3ca2d0), runs the fetch SM, on a hit resolves the room (FUN_0060e820,0x3c98b0), validates the slot (+0x25c>=0), claims ownership (FUN_0060f2c0), primes send (FUN_006153b0/006150b0) and arms a 0x3c countdown. Returns SN@P error codes -1..-5.

## Notes / uncertainty
Already fully reconstructed: join-existing driver; op09 register (tmpl 0x3ca2d0) -> roomlist_fetch_sm -> op06 enter (tmpl 0x3c98b0) -> slot validate +0x25c>=0 -> claim ownership -> prime send. Client-local success(1) vs server op06-accept is separate (create-room blocker).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00610580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
