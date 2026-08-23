# 0x001c3340 netbuf_init_mode2

| field | value |
|---|---|
| Original address | 0x001c3340 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3340 |
| Resolved name | netbuf_init_mode2 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001c2da0
**Referenced globals:** 0x365a70 cfg-blob
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Init for connection mode 2: FUN_001c2da0(2) then copies a 0x4c-byte config blob into 0x365a70.

## Notes / uncertainty
Mode-2: copies 0x4c-byte config blob into 0x365a70 (ctx-0x50). Struct layout of the config blob unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
