# 0x005d6c90 session_pool_free_node

| field | value |
|---|---|
| Original address | 0x005d6c90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6c90 |
| Resolved name | session_pool_free_node |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7760, FUN_005d8340
**Callees:** FUN_005d6b80
**Referenced globals:** 0x004f370 (base+off: session pool head)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x10c buffer; node+0x110 len

## Behavioral explanation
Returns a node to the session pool (head base+0x4f370) and clears its 0x8000-byte data buffer at +0x10c and length +0x110.

## Notes / uncertainty
Returns node to freelist@net+0x4f370, memsets its 0x8000 response buffer(*+0x10c) and zeroes len(+0x110); does not null the buffer ptr (buffer pooled with node). Full node header layout partial.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
