# 0x005efae0 ui_stringbuf_pop

| field | value |
|---|---|
| Original address | 0x005efae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005efae0 |
| Resolved name | ui_stringbuf_pop |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f21f0, FUN_005f2280
**Callees:** —
**Referenced globals:** +0xe96a ring index; +0xd96a 256B record ring
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe96a

## Behavioral explanation
Pops the string/label ring: decrements counter +0xe96a (floored at 0) and returns the current record address.

## Notes / uncertainty
Exact inverse of efa60; decrements depth floored at 0, returns top slot. No pass gate (used inside draw traversal).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005efae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
