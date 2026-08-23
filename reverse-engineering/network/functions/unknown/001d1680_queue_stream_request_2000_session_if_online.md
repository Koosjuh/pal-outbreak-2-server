# 0x001d1680 queue_stream_request_2000_session_if_online

| field | value |
|---|---|
| Original address | 0x001d1680 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1680 |
| Resolved name | queue_stream_request_2000_session_if_online |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80
**Referenced globals:** 0x343577 disc flag; 0x34357a stage/id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Disc-gated stream request (uRam0034357a, 0x2000) via FUN_001ccb80.

## Notes / uncertainty
If online: FUN_001ccb80(session_id 0x34357a, 0x2000). Session-keyed; kind meaning inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
