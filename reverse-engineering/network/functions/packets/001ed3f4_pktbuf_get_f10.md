# 0x001ed3f4 pktbuf_get_f10

| field | value |
|---|---|
| Original address | 0x001ed3f4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed3f4 |
| Resolved name | pktbuf_get_f10 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e3880
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x10

## Behavioral explanation
Getter: returns header field at buf+0x10.

## Notes / uncertainty
Getter +0x10; caller FUN_001e3880 copies it into recv wire header -> [inferred] seq/msg-id. Field semantic inferred, not proven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed3f4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
