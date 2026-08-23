# 0x005e9380 cfg_reset_addr_field

| field | value |
|---|---|
| Original address | 0x005e9380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9380 |
| Resolved name | cfg_reset_addr_field |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef0e0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x101c (0x101 str buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Applies via FUN_005ef0e0(arg) then zeroes the 0x101-byte buffer at cfg+0x101c.

## Notes / uncertainty
Config-directive handler: commits pending field (FUN_005ef0e0) then memsets addr/proxy string cfg+0x101c (0x101). Selecting keyword + what FUN_005ef0e0 commits unknown; 0 static callers = parser table entry.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
