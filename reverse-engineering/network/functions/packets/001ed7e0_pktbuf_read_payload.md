# 0x001ed7e0 pktbuf_read_payload

| field | value |
|---|---|
| Original address | 0x001ed7e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed7e0 |
| Resolved name | pktbuf_read_payload |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e366c, FUN_001e3880
**Callees:** FUN_001069a8, FUN_001ebca8, FUN_001ed6bc
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length

## Behavioral explanation
Copies min(used-length, param_3) bytes of payload out to param_2; returns bytes copied (peek/read of payload).

## Notes / uncertainty
Non-destructive peek: copies min(used_len,max_len) from payload; returns count. used_len compared signed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed7e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
