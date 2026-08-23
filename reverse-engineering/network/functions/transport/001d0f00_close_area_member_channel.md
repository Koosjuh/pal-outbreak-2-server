# 0x001d0f00 close_area_member_channel

| field | value |
|---|---|
| Original address | 0x001d0f00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0f00 |
| Resolved name | close_area_member_channel |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80
**Referenced globals:** conn+0xbc8 seq; conn+0x549 mode; conn+3 index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Mirror of the cf3e0 send but tears down: selects channel (idx*8 + 0x1000/0x1100 by mode byte@0x549 and seq@0xbc8) and calls FUN_001ccb80 to close/unsubscribe it.

## Notes / uncertainty
Emits member-channel close via FUN_001ccb80; reliable(0x8000)+seq only when conn+0xbc8 pending; base 0x1000/0x1100 by mode byte. Field names inferred, no live trace.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0f00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
