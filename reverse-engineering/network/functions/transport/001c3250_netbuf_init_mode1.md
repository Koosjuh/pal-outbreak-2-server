# 0x001c3250 netbuf_init_mode1

| field | value |
|---|---|
| Original address | 0x001c3250 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3250 |
| Resolved name | netbuf_init_mode1 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001c2da0, FUN_001c2f30
**Referenced globals:** 0x3435fc heap-base; 0x3619d0 marker-buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Init for connection mode 1: FUN_001c2da0(1), zero rx (0x3000), fill 0x3619d0 with 0xff, reset reassembly (FUN_001c2f30).

## Notes / uncertainty
Mode-1: single rx region, 0x3619d0 filled 0xff (inferred seq/ack bitmap), FUN_001c2f30 reassembly reset. Bitmap semantics inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
