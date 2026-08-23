# 0x001dd1dc snap_send_leave_nodata

| field | value |
|---|---|
| Original address | 0x001dd1dc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dd1dc |
| Resolved name | snap_send_leave_nodata |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x61b(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x07
**State vars:** 0x50c(send-lock); 0x61b(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends a zero-length opcode-7 with who 0xa000 (DATA-less leave variant); completion cb 0x24, seq conn+0x61b.

## Notes / uncertainty
op07 leave zero-length, who 0xa000; cb 0x24, seq 0x61b. CORRECTION: 0xa000 keeps 0x8000 reliable bit, so this is reliable, NOT unreliable — old _unrel suffix is a misnomer; only the 0x1000 DATA bit differs from dd07c.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dd1dc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
