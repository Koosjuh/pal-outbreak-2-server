# 0x001d16b0 request_stream_2400

| field | value |
|---|---|
| Original address | 0x001d16b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d16b0 |
| Resolved name | request_stream_2400 |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80
**Referenced globals:** 0x343577 disc flag; 0x34357a stage/id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Disc-gated stream request (uRam0034357a, 0x2400) via FUN_001ccb80.

## Notes / uncertainty
Disc-gated (cRam00343577==0) fixed 0x2400 stream request via FUN_001ccb80(section_id,0x2400). Meaning of 0x2400 arg (len vs offset) inferred. Not network — asset streaming.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d16b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
