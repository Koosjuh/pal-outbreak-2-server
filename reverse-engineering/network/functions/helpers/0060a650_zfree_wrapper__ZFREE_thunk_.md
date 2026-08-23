# 0x0060a650 zfree_wrapper (ZFREE thunk)

| field | value |
|---|---|
| Original address | 0x0060a650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060a650 |
| Resolved name | zfree_wrapper (ZFREE thunk) |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00608ab0, FUN_00608c80
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Indirect ZFREE: calls the free callback at state+0x2c with opaque+0x30 and the given pointer.

## Notes / uncertainty
zlib ZFREE macro out-of-lined: (*z->zfree)(z->opaque,ptr). 'Jumptable not recovered' is just the indirect tail-call.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060a650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
