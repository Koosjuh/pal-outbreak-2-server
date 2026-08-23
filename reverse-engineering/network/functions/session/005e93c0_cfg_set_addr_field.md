# 0x005e93c0 cfg_set_addr_field

| field | value |
|---|---|
| Original address | 0x005e93c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e93c0 |
| Resolved name | cfg_set_addr_field |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x101c (0x100 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x100-byte string into cfg+0x101c (address/proxy field).

## Notes / uncertainty
Copies argument token (<=0x100) into addr/proxy string cfg+0x101c via FUN_005ec1b0. Exact copy/termination semantics of FUN_005ec1b0 assumed strncpy-like; selecting keyword unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e93c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
