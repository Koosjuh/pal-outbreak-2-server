# 0x005af2c0 ui_draw_set_color

| field | value |
|---|---|
| Original address | 0x005af2c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af2c0 |
| Resolved name | ui_draw_set_color |
| Subsystem | ui |
| Relevance | helper |
| Status | documented (opaque body — halt_baddata; not reconstructable) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** 59 — the same draw fan-in as `ui_draw_text`/`ui_draw_set_size` (FUN_005ac4c0, FUN_005b76f0, FUN_005b7de0, FUN_005fd9e0, FUN_00628860, FUN_00629d60, FUN_0062fa80 …)
**Callees:** — (leaf)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draw-state setter invoked immediately before `ui_draw_text` throughout the overlay, almost always in the fixed triple `ui_draw_set_color → ui_draw_set_size → ui_draw_text`. Sets the pen color/palette for the following draw. The body cannot be read: Ghidra decodes it as `halt_baddata` (a VU/MMI or coprocessor macro the disassembler rejects), so the role is inferred purely from its call-site pairing and name, not from its instructions.

## Input / output
- Signature not recoverable from the decompile (`void FUN_005af2c0(void)` is a decoder artifact; the real call passes a color argument in a register). [inferred] one integer color/palette id.
- returns void.

## Side effects
- Programs the base-module draw color state [inferred]. No overlay globals visible.

## Important branches
- Not decodable (single bad-instruction block).

## Constants & flags
- None recoverable.

## Corrected reconstruction
Not reconstructable — opaque. Low-level fact preserved verbatim:
```
FUN_005af2c0:  halt_baddata   ; Ghidra: "Bad instruction - Truncating control flow here"
               ; body is an undecoded VU/MMI/COP macro; behavior inferred, not read
```

## Evidence
- Raw decompile (`FUN_005af2c0.c`): entire body is `halt_baddata()`.
- Role inferred from the invariant call pattern with `ui_draw_set_size` + `ui_draw_text` across 59 sites. Runtime-unvalidated. Confidence capped at Medium — no instruction-level proof.

## Remaining uncertainty
- Argument count/type and whether it sets color vs a broader draw mode are unproven; disassembly would need a raw-bytes / alternate-decoder pass.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af2c0.c`  — untouched decompiler output.
