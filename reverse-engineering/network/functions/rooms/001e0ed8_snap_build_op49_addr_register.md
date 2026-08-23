# 0x001e0ed8 snap_build_op49_addr_register

| field | value |
|---|---|
| Original address | 0x001e0ed8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0ed8 |
| Resolved name | snap_build_op49_addr_register |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_00106b60, FUN_0010a4f0, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001e2304, FUN_001ebca8, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x25b78c conn ptr; 0x25b790 last-error code; conn+0x50c busy/guard; conn+0x520 pool
**Referenced strings:** —
**Referenced opcodes:** 0x49
**State vars:** conn+0x50c busy-guard; 0x25b790 error(0x65/0x66)

## Behavioral explanation
Builds the reliable op-0x49 (room-list/register) payload: iterates up to 0x20 address entries (stride 0xc), encodes each by type (1->0xd,2->0x15,else->9 bytes) with byteswapped fields, then hands to the packet enqueuer with opcode 0x49 / who-byte 0xb000.

## Notes / uncertainty
Renamed from ...roomlist_register to ...addr_register. Client->server op49 REGISTER: up to 32 addr entries (stride 0xc), type=(flags>>5) -> 0xd(pair)/0x15(16B/IPv6)/9(single u32); header key+count; completion tag 0x32. Address-type meaning inferred; distinct from server->client op49 room-list decode (0x1c70b0).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0ed8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
