# 0x001c32b0 netbuf_init_mode3

| field | value |
|---|---|
| Original address | 0x001c32b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c32b0 |
| Resolved name | netbuf_init_mode3 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c2da0
**Referenced globals:** 0x365ac4/0x365ac8 peer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Init for connection mode 3: FUN_001c2da0(3) then stores two params (peer addr/port) into 0x365ac4/0x365ac8.

## Notes / uncertainty
Mode-3: explicit-peer connect; stores param1/param2 into ctx+0x04/+0x08 (peer_addr/port). Param types inferred from offset position.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c32b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
