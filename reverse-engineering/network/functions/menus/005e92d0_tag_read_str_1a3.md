# 0x005e92d0 tag_read_str_1a3

| field | value |
|---|---|
| Original address | 0x005e92d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e92d0 |
| Resolved name | tag_read_str_1a3 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg/state base); cfg+0x1a3 (str field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x100-byte string token into cfg+0x1a3.

## Notes / uncertainty
256B string ctx+0x1a3; consumed by FUN_005d95f0 via FUN_005ef3f0. Upgraded Medium->High: consumer path now identified. Consumer's exact use (layout vs substitution) uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e92d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
