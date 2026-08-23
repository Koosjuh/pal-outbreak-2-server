# 0x0062b500 text_tag_substitute

| field | value |
|---|---|
| Original address | 0x0062b500 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062b500 |
| Resolved name | text_tag_substitute |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062b2c0
**Callees:** FUN_0062b620
**Referenced globals:** 0x715480 token buf; 0x66ae10 tag table
**Referenced strings:** DUMMY
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses '<...>' markup tokens in a string against an 11-entry table (PTR_s_DUMMY_0066ae10) and emits substitutions/verbatim into an output buffer.

## Notes / uncertainty
<tag> markup expander: verbatim copy except <...> tokens matched against 11-entry table 0x66ae10 (strcmp); indices {0,1,5,6,7} drop, 8 terminates, else emit verbatim. Concrete meaning of each table entry not decoded; relies on tag-8 terminator (no length bound).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062b500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
