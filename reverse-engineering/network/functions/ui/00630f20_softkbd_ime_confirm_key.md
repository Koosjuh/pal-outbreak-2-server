# 0x00630f20 softkbd_ime_confirm_key

| field | value |
|---|---|
| Original address | 0x00630f20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630f20 |
| Resolved name | softkbd_ime_confirm_key |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0, FUN_00634ab0
**Callees:** FUN_00630c50, FUN_00633430, FUN_00633470, FUN_00633930, FUN_00633ab0, FUN_006352e0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state (0-3); +0x30 mode; +0x260 IME buffer; +0x248 result code; +8 field ptr

## Behavioral explanation
IME conversion-state handler (key 0x2c): branches on IME state (+0x2f) to advance/confirm/abort the composition and set the result code.

## Notes / uncertainty
Confirm/next-candidate key (0x2c); branches on IME state (+0x2f) to commit field vs cycle kanji candidates. param_1 confirm(0)/advance(!=0) and IME-state enum labels inferred from control flow, not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630f20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
