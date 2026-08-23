# 0x005c4690 get_room_addr_port

| field | value |
|---|---|
| Original address | 0x005c4690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4690 |
| Resolved name | get_room_addr_port |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00606520
**Callees:** —
**Referenced globals:** 0x6fb74a-0x6fb753 (room host address+port bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Assembles a 4-byte address word (0x6fb74a..4d) and a byte-swapped 16-bit port (0x6fb752/53) from the room detail block into the caller's out pointers.

## Notes / uncertainty
Extracts room host IPv4 (0x6fb74a..4d) + byte-swapped port (0x6fb752/53) into out-params for socket connect. Endianness at socket boundary and room-detail base offset not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
