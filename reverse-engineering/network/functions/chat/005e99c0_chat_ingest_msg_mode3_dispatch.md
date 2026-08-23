# 0x005e99c0 chat_ingest_msg_mode3_dispatch

| field | value |
|---|---|
| Original address | 0x005e99c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e99c0 |
| Resolved name | chat_ingest_msg_mode3_dispatch |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ecf20
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x17f (msg mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x17f

## Behavioral explanation
Parses a message, sets mode 0x17f=3 and dispatches it through FUN_005ecf20.

## Notes / uncertainty
Mode-3 sibling of 0x5e9940: decodes, sets msg_mode=3, dispatches text to FUN_005ecf20 (not stored to a display buffer). Special/command message class. No caller; consumer 0x5ecf20 undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e99c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
