# 0x00605d30 socket_connect

| field | value |
|---|---|
| Original address | 0x00605d30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605d30 |
| Resolved name | socket_connect |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606000, FUN_00606520
**Callees:** FUN_00605d00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper that opens/connects a socket to (addr,port) via func_0x001ee3f0 and resets the recv framer.

## Notes / uncertainty
Marshals {addr:u32,port:u16,extra:u16} and calls connect prim func_0x001ee3f0, then recv_framer_reset. Void wrapper hides connect result/errno; param_3 (proto vs alt-port) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605d30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
