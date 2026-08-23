# 0x001ed634 pktbuf_set_f24

| field | value |
|---|---|
| Original address | 0x001ed634 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed634 |
| Resolved name | pktbuf_set_f24 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d5ae4, FUN_001d6988, FUN_001e16b4
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x24

## Behavioral explanation
Setter: writes buf+0x24 = param_2, returns it.

## Notes / uncertainty
Setter for pktbuf header word +0x24 (inside cloned 0x10..0x2c header block). Mechanics certain; exact semantic of the field (seq/who/tag) unproven at runtime.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed634.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
