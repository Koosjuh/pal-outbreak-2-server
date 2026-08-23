# 0x001cf3e0 send_area_member_update

| field | value |
|---|---|
| Original address | 0x001cf3e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf3e0 |
| Resolved name | send_area_member_update |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ab460, FUN_001cbc20, FUN_001cce80, FUN_001cf360, FUN_001cf570
**Referenced globals:** 0x4ee098/0x4ed890 send buffers; cRam00343577 offline-mode flag; conn+0xbc8 seq; conn+0x549 mode; conn+3 index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Selects channel (idx*8 + 0x1000/0x1100 by mode byte@0x549), presets attributes, allocs a 0x20 message and opens a reliable send via FUN_001cce80 with packed routing; on mode==1 also calls FUN_001cf570.

## Notes / uncertainty
Reliable area/member update push: channel slot*8+0x1100(role1)/0x1000, pending-seq folds 0x8000 resume marker, alloc 0x20 @slot*0x1468, send flag role<<0x1d|2; offline-gated. Opcode not pinned to PACKET_INDEX (lower channel than op06 0x1800); role@+0x549 inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf3e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
