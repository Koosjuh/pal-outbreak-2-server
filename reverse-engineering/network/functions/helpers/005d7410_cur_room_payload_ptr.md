# 0x005d7410 cur_room_payload_ptr

| field | value |
|---|---|
| Original address | 0x005d7410 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7410 |
| Resolved name | cur_room_payload_ptr |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9690, FUN_005c9900, FUN_005cc980, FUN_005d47f0, FUN_005d7420, FUN_005d74a0, FUN_005d76b0, FUN_005d7e00, FUN_005d7f80, FUN_005dbca0
**Callees:** —
**Referenced globals:** 0x00701018 current room
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701018

## Behavioral explanation
Accessor returning current-room node + 4 (room payload/body pointer).

## Notes / uncertainty
Getter: room node base+4 (payload past 4-byte header). 10 callers use it as room-record base. Node layout [+0 hdr/+4 payload/+0x108 who-bytes]. Field detail lives in room_record.md; not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7410.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
