# 0x005c5810 build_room_status_text

| field | value |
|---|---|
| Original address | 0x005c5810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5810 |
| Resolved name | build_room_status_text |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c40a0
**Callees:** FUN_005c2a70, FUN_005c5780
**Referenced globals:** 0x6fbe58 status-buf; 0x700420/424/428 room-slots; 0x700470 room-flags; 0x700434 host-name; 0x700454 detail; 0x6405c0/0x6405c8 fmt-str
**Referenced strings:** fmt@0x6405c0; fmt@0x6405c8
**Referenced opcodes:** —
**State vars:** uRam00700470 room-flags (0x40000000/0x80000)

## Behavioral explanation
Composes the room/connection status line into 0x6fbe58 by inspecting room-state globals (0x700420/424/428, 0x700470 flags) and host name.

## Notes / uncertainty
5-way room-status composer into 0x6fbe58 gated by progress ints 0x700420/424/428 + flags 0x700470 (0x40000000 busy, 0x80000 has-detail). Host short-code + FUN_005c2a70 mapping inferred; not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
