# 0x001ed4fc pktbuf_get_f1c

| field | value |
|---|---|
| Original address | 0x001ed4fc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed4fc |
| Resolved name | pktbuf_get_f1c |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001e19c4, FUN_001e3880
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x1c

## Behavioral explanation
Getter: returns header field at buf+0x1c (a seq/counter compared in FUN_001ed554).

## Notes / uncertainty
Getter +0x1c = retransmit backoff accumulator (grows +200/attempt in FUN_001d5460); also emitted as 16-bit in recv header FUN_001e3880. Possibly overloaded per direction.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed4fc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
