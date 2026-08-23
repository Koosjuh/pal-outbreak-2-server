# 0x001dc508 snap_send_create_room

| field | value |
|---|---|
| Original address | 0x001dc508 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dc508 |
| Resolved name | snap_send_create_room |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109eb8, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x616(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x04
**State vars:** 0x50c(send-lock); 0x616(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable opcode-4 with a 0x2c-byte struct: name (FUN_00109eb8), a packed 16-bit field, optional string (+0x14), and two more packed shorts/u32; completion cb 0x1f, seq conn+0x616.

## Notes / uncertainty
The real op04 create-slot/room builder: 0x2c-byte struct name[16]+htonl(u16 max)@0x10+password[16]@0x14+htonl(u16 flags)@0x24+htonl(u32 scenario)@0x28; cb 0x1f, seq 0x616. Field roles (max/flags/scenario) inferred from room_record, not runtime-proven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dc508.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
