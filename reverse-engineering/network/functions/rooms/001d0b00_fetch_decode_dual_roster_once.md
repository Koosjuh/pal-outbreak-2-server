# 0x001d0b00 fetch_decode_dual_roster_once

| field | value |
|---|---|
| Original address | 0x001d0b00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0b00 |
| Resolved name | fetch_decode_dual_roster_once |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001aa780, FUN_001ab6d0, FUN_001cb360, FUN_001d0a50
**Referenced globals:** cRam004fa64f done-once flag; uRam003435bc work base; uRam0034357a session id
**Referenced strings:** 0x24ccd0 template
**Referenced opcodes:** —
**State vars:** cRam004fa64f; uRam0034357a

## Behavioral explanation
One-shot (guarded by cRam004fa64f): builds tmpl 0x24ccd0 (uRam0034357a), sends via FUN_001cb360 (flags 0x20001) and decodes the reply into dual grids via FUN_001d0a50; sets the done-flag.

## Notes / uncertainty
One-shot latched by cRam004fa64f: format template 0x24ccd0 w/ id 0x34357a, request via FUN_001cb360 flags 0x20001, decode reply into dual grids FUN_001d0a50. 'dual roster' inferred; flag 0x20001 class + reply payload not decoded; no callers recorded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0b00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
