# 0x006353e0 kbd_append_char_or_space

| field | value |
|---|---|
| Original address | 0x006353e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006353e0 |
| Resolved name | kbd_append_char_or_space |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006352e0
**Callees:** FUN_00631ff0, FUN_006320f0, FUN_006343b0, FUN_00634970, FUN_00635900
**Referenced globals:** 0x715da8 kbd/text-entry state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x2f mode; 0x260 preedit-count; 0x2a text-len; 0x248 status; 0x4c text-buffer; 0x2a/0x3a encoder args

## Behavioral explanation
Appends an input keycode (special-cases 0x20) to the text buffer at 0x4c via the encoder, advancing length 0x2a; guards on preedit(0x2f)/count(0x260).

## Notes / uncertainty
Appends one char via encoder FUN_006320f0 into text_buf(+0x4c), advances +0x2a, status +0x248=1; 0x20 = space/confirm keycode. FUN_006343b0 predicate meaning (confirm vs non-empty) not reconstructed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006353e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
