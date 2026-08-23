# 0x001dd33c snap_send_register

| field | value |
|---|---|
| Original address | 0x001dd33c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dd33c |
| Resolved name | snap_send_register |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x61c(seq)
**Referenced strings:** 'NAME' (0x4e414d45 tag literal)
**Referenced opcodes:** 0x08
**State vars:** 0x50c(send-lock); 0x61c(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-8 register (who param5|0xa000): u32 tag (param_2) + variable blob; skips the tag byteswap when tag == 'NAME' (0x4e414d45); completion cb 0x25, seq conn+0x61c.

## Notes / uncertainty
op0x08 register: 4-byte tag(BE)+value blob, who=subchan|0xa000, seq conn+0x61c, cb 0x25. 'NAME' tag (0x4e414d45) skips value byteswap. Full tag set (USER/MAXI) inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dd33c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
