# 0x001c4070 snap_send_op0e_flush

| field | value |
|---|---|
| Original address | 0x001c4070 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4070 |
| Resolved name | snap_send_op0e_flush |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3420, FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** conn+0x28 hdr; conn+0x38 len; conn+0x1c socket
**Referenced strings:** —
**Referenced opcodes:** 0x0e
**State vars:** —

## Behavioral explanation
Builds and transmits a bare control packet (opener FUN_001c3420 with tag 0xe) — finalizes length and sends; no app payload.

## Notes / uncertainty
Builds+sends control tag 0x0e: FUN_001c3420(ctx,0xe) open, FUN_001c3c90 seal, BE-length header, FUN_001ee590 checksum+send, FUN_001c3840 drain (ret>-2 -> 0). Does NOT set stage byte. Seal/drain internals untraced; Medium.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
