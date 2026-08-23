# 0x001dc9fc snap_send_join

| field | value |
|---|---|
| Original address | 0x001dc9fc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dc9fc |
| Resolved name | snap_send_join |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x618(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** 0x50c(send-lock); 0x618(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-6 with a single htonl u32 (room id) — member JOIN/enter; completion cb 0x21, seq conn+0x618.

## Notes / uncertainty
op06 member-JOIN, single htonl(u32) room id, who 0xb000; cb 0x21, seq 0x618. Shares seq/cb with dcbf4 (named variant). u32 = room handle vs internal index inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dc9fc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
