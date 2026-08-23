# 0x005e9940 chat_ingest_msg_hash_prefix

| field | value |
|---|---|
| Original address | 0x005e9940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9940 |
| Resolved name | chat_ingest_msg_hash_prefix |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x17f (msg mode); cfg+0x8f6 (system msg buf); cfg+0x9f6 (normal msg buf)
**Referenced strings:** '#' (system-message prefix)
**Referenced opcodes:** —
**State vars:** cfg+0x17f

## Behavioral explanation
Parses a message; if it starts with '#' sets mode 0x17f=1 and stores at cfg+0x8f6, else mode=2 and stores at cfg+0x9f6.

## Notes / uncertainty
Decodes msg (0x5ec1b0, 0x100 buf); '#'→msg_mode=1 system line cfg+0x8f6, else msg_mode=2 normal cfg+0x9f6. cfg via *(0x7012a0). One of 3 mode-ingest siblings. No caller; 0x5ec1b0 decode internals not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
