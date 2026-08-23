# 0x00186610 read_triple_at_0x30

| field | value |
|---|---|
| Original address | 0x00186610 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00186610 |
| Resolved name | read_triple_at_0x30 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d1e40
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Copies 3 u32 from src+0x30/+0x34/+0x38 into param_1[0..2]. Unambiguous; semantic identity of the triple depends on unidentified source struct.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00186610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
