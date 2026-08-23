# 0x001d1640 queue_stream_request_2a00_if_online

| field | value |
|---|---|
| Original address | 0x001d1640 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1640 |
| Resolved name | queue_stream_request_2a00_if_online |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80
**Referenced globals:** 0x343577 disc/HDD mode flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
When disc-mode flag clear, issues a stream/sound request (id<<16, 0x2a00) via FUN_001ccb80.

## Notes / uncertainty
If online (343577==0): FUN_001ccb80(index<<16, 0x2a00). Kind 0x2a00 meaning + offline polarity inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1640.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
