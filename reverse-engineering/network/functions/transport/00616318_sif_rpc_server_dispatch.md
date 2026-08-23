# 0x00616318 sif_rpc_server_dispatch

| field | value |
|---|---|
| Original address | 0x00616318 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616318 |
| Resolved name | sif_rpc_server_dispatch |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x70f2c8 (handler fno 0x0d); 0x70f2c4 (handler fno 0x0c); 0x70f2cc (handler fno 0x0e)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** rpc fno 0x0c/0x0d/0x0e handler ptrs

## Behavioral explanation
IOP-side (or callback) SIF-RPC service dispatcher: routes function-numbers 0x0c/0x0d/0x0e to registered handler pointers, unpacking the request buffer into their args.

## Notes / uncertainty
EE-side SIF-RPC server callback (svc 0x80001101) for IOP->EE upcalls. Routes fno 0x0c/0x0d/0x0e to registered handler ptrs 0x70f2c4/c8/cc, unpacks buffer, writes result to buf[0], -1 on unknown. Handler role labels (data/event/disconnect) inferred from arg arity.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616318.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
