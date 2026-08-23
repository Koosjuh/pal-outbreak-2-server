# 0x005c5ad0 register_conn_slot

| field | value |
|---|---|
| Original address | 0x005c5ad0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5ad0 |
| Resolved name | register_conn_slot |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c40a0
**Callees:** FUN_005be0a0, FUN_005c6fb0
**Referenced globals:** 0x6ca97c slot-hash; 0x6ca97e slot-sendid; 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a connection slot (FUN_005be0a0), stores its conn-hash and a registration send-handle keyed by the connID token with a trailing '-' delimiter.

## Notes / uncertainty
Allocs a 0x20-stride slot, stores conn-hash at 0x6ca97c and register send-id at 0x6ca97e, sends the reliable register msg (token + '-' delimiter, <0xf). The exact opcode of the register send (likely op09) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5ad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
