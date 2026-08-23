# 0x001e2610 socket_layer_init

| field | value |
|---|---|
| Original address | 0x001e2610 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2610 |
| Resolved name | socket_layer_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_001e2424
**Referenced globals:** 0x25b79c net device handle; PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x25b79c device handle

## Behavioral explanation
Entry-point initializer for the socket layer: runs socket_table_init and records the network device handle into DAT_0025b79c.

## Notes / uncertainty
Entry point: socket_table_init(param_2 name_list) then DAT_0025b79c=param_1 handle. Arg order handle=p1, list=p2.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
