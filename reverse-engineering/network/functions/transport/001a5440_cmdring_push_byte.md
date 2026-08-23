# 0x001a5440 cmdring_push_byte

| field | value |
|---|---|
| Original address | 0x001a5440 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a5440 |
| Resolved name | cmdring_push_byte |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d3130
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
32-entry ring @0x29b000 stride0xc, index uRam0029afe8&0x1f: if slot word0<0 (free) write 0x4A000000|(sext8(payload)<<16), advance, return 0; else -1. What the ring drives and 0x4A tag unknown; +4/+8 unused here.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a5440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
