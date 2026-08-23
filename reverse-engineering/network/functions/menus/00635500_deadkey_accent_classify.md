# 0x00635500 deadkey_accent_classify

| field | value |
|---|---|
| Original address | 0x00635500 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635500 |
| Resolved name | deadkey_accent_classify |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630750, FUN_00637bf0
**Callees:** —
**Referenced globals:** 0x715b78 pending dead-key accent class
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715b78 accent-class

## Behavioral explanation
Classifies a dead-key accent scancode (0xa8 diaeresis,0x7e tilde,0xb4 acute,0x60 grave,0x5e circumflex) to class index 0-4 in uRam00715b78, else 0xff.

## Notes / uncertainty
Maps dead-key scancode->accent class 0-4 (^/`/´/~/¨) else 0xFF, into 0x715b78. Mapping certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
