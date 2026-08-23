# 0x005c7320 build_send_loid_stat_msg

| field | value |
|---|---|
| Original address | 0x005c7320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7320 |
| Resolved name | build_send_loid_stat_msg |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c72d0
**Callees:** FUN_005bf1e0, FUN_005c3e50
**Referenced globals:** 0x6fec28 (member table, 0x24 stride); 0x640580 (STAT payload); 0x6febac (conn); 0x7006ac; 0x7005f8 (reply ctx)
**Referenced strings:** LOID; STAT
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds a LOID/STAT status app-message for the current member slot (DAT_00640580 payload) and sends it reliably with reply cb FUN_005c7790.

## Notes / uncertainty
Builds LOID/STAT field descriptor (member slot ptr + two 0x21 STAT fields from DAT_00640580) and queues via 0x001e0ed8 + reply handler 0x5c7790. Descriptor layout exact; on-wire serialization by 0x001e0ed8 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
