# 0x001dcbf4 snap_send_join_named

| field | value |
|---|---|
| Original address | 0x001dcbf4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dcbf4 |
| Resolved name | snap_send_join_named |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a4f0, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001e2304, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x618(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** 0x50c(send-lock); 0x618(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable opcode-6 (len 0x14): htonl u32 (room id) + optional 16-byte string (password/name); completion cb 0x21, seq conn+0x618.

## Notes / uncertainty
op06 named join, 0x14 body: htonl(u32) id + optional 16-byte cred string; who 0xb000, cb 0x21, seq 0x618 (shared with dc9fc). String = password vs joiner-name inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dcbf4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
