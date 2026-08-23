# 0x00637980 kbd_char_is_rejected

| field | value |
|---|---|
| Original address | 0x00637980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637980 |
| Resolved name | kbd_char_is_rejected |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630750, FUN_00630910, FUN_006379e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Char validity predicate: returns 0 (printable/allowed) for 0x20-0x7e and the 9999 sentinel and 0x2c, else 1 (reject).

## Notes / uncertainty
CORRECTION: char predicate returns 0=accept/1=reject; comma 0x2c is REJECTED (reserved delimiter) — prior record wrongly listed it as allowed. 9999 sentinel accepted, printable 0x20-0x7e accepted, else rejected.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
