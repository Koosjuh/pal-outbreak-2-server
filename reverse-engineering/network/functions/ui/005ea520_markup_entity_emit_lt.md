# 0x005ea520 markup_entity_emit_lt

| field | value |
|---|---|
| Original address | 0x005ea520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea520 |
| Resolved name | markup_entity_emit_lt |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eee00
**Referenced globals:** +4 (output length counter); +0xd8e4 (overflow-flush target)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4

## Behavioral explanation
Entity handler: appends ASCII '<' (0x3c) to the output buffer, NUL-terminates, guards buffer at 0x7d via flush.

## Notes / uncertainty
Appends ASCII '<' 0x3c to out buffer, NUL-term, flush (FUN_005eee00) when len +0x04 > 0x7d (~128B line). One of 6 entity emitters. FUN_005eee00 flush semantics not deeply resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea520.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
