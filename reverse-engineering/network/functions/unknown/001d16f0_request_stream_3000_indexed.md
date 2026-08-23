# 0x001d16f0 request_stream_3000_indexed

| field | value |
|---|---|
| Original address | 0x001d16f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d16f0 |
| Resolved name | request_stream_3000_indexed |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80
**Referenced globals:** 0x343577 disc flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Disc-gated indexed stream request (id&0xff -> (id*8)+0x3000) via FUN_001ccb80.

## Notes / uncertainty
Indexed variant of 16b0: request id=idx&0xff, param=idx*8+0x3000 (8-byte stride implies descriptor table). Same disc-mode gate. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d16f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
