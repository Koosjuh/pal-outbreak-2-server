# 0x005af2e0 ui_draw_set_size

| field | value |
|---|---|
| Original address | 0x005af2e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af2e0 |
| Resolved name | ui_draw_set_size |
| Subsystem | ui |
| Relevance | helper |
| Status | documented (opaque body — halt_baddata; not reconstructable) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** 51 — same draw fan-in as `ui_draw_set_color`/`ui_draw_text` (FUN_005ac4c0, FUN_005b76f0, FUN_005b86c0, FUN_005fd9e0, FUN_00628860, FUN_00629d60, FUN_0062fa80 …)
**Callees:** — (leaf)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Second setter in the `set_color → set_size → draw_text` triple. Sets the glyph/sprite size (or scale) for the following draw. Body is undecodable (`halt_baddata`), so role is inferred from call-site pairing and the observation that its argument at call sites is always a small size constant (0x10 / 0x14 / 0x1c) — consistent with a font/cell pixel size.

## Input / output
- Signature not recoverable (`void FUN_005af2e0(void)` is a decoder artifact). [inferred] one integer size constant (~16/20/28 px).
- returns void.

## Side effects
- Programs the base-module draw size/scale state [inferred]. No overlay globals visible.

## Important branches
- Not decodable (single bad-instruction block).

## Constants & flags
- Caller-supplied size constants observed: 0x10, 0x14, 0x1c [inferred glyph cell size in px].

## Corrected reconstruction
Not reconstructable — opaque. Low-level fact preserved verbatim:
```
FUN_005af2e0:  halt_baddata   ; Ghidra: "Bad instruction - Truncating control flow here"
               ; body is an undecoded VU/MMI/COP macro; behavior inferred, not read
```

## Evidence
- Raw decompile (`FUN_005af2e0.c`): entire body is `halt_baddata()`.
- Role inferred from fixed pairing with `ui_draw_set_color`/`ui_draw_text` and small-constant arguments at 51 sites. Runtime-unvalidated. Confidence capped at Medium.

## Remaining uncertainty
- Whether the argument is a pixel size, a scale factor, or a font index is unproven. Needs a raw-bytes decode pass.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af2e0.c`  — untouched decompiler output.
