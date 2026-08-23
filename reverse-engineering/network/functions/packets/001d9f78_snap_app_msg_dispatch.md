# 0x001d9f78 snap_app_msg_dispatch

| field | value |
|---|---|
| Original address | 0x001d9f78 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d9f78 |
| Resolved name | snap_app_msg_dispatch |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6dfc
**Callees:** FUN_001d507c, FUN_001d7ab0, FUN_001d7b30, FUN_001d7f6c, FUN_001d8048, FUN_001d80c8, FUN_001d84cc, FUN_001d861c, FUN_001d8848, FUN_001d89f8, FUN_001d8ab0, FUN_001d8b60, FUN_001d8c10, FUN_001d8cc0, FUN_001d8d70, FUN_001d8e20, FUN_001d8ed8, FUN_001d90ec, FUN_001d91c0, FUN_001d9354, FUN_001d93d4, FUN_001d9550, FUN_001d9678, FUN_001d9b6c, FUN_001dbd0c
**Referenced globals:** conn+0x548..0x610(app callback table); conn+0x5b8..0x610(sub-selector cbs); conn+0x44; conn+0x7c; conn+0x80
**Referenced strings:** —
**Referenced opcodes:** 0x03, 0x04, 0x05, 0x06, 0x0c, 0x0d, 0x0f, 0x10, 0x11, 0x22, 0x2a, 0x2b, 0x2e, 0x3d, 0x40, 0x44, 0x45, 0x46, 0x48, 0x6b, 0x75
**State vars:** 0x80(conn-state); 0x7c

## Behavioral explanation
Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

## Notes / uncertainty
Already fully reconstructed and faithful to raw (verified): sel-3 outer switch, who/flags bits (0x1000 DATA/0x2000 selector/0x8000 reliable/0x400 marker/0x3ff len), conn+0x548..0x610 handler table, op28 sub-selector nested switch. Uncertainty: semantic label of each conn+0x5xx slot (member-list vs chat vs room-detail) is opcode-inferred, not runtime-traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d9f78.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
