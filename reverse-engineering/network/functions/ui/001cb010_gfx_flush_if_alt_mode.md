# 0x001cb010 gfx_flush_if_alt_mode

| field | value |
|---|---|
| Original address | 0x001cb010 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb010 |
| Resolved name | gfx_flush_if_alt_mode |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** func_0x003acd90
**Referenced globals:** 0x343575=mode flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x343575=mode flag

## Behavioral explanation
If a global mode flag is set, calls an external routine (func_0x003acd90); otherwise nothing.

## Notes / uncertainty
If mode flag 0x343575==1 delegate to external 0x3ACD90, else no-op. Graphics dispatch shim, NOT protocol; same flag gates the teardown divert. External target undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
