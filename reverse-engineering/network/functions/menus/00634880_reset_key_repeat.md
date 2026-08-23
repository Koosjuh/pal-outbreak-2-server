# 0x00634880 reset_key_repeat

| field | value |
|---|---|
| Original address | 0x00634880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634880 |
| Resolved name | reset_deadkey_state |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630e40, FUN_00631ff0, FUN_006345e0, FUN_006355a0, FUN_00635cb0
**Callees:** —
**Referenced globals:** 0x715b78 (pending dead-key accent class)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715b78

## Behavioral explanation
Clears the pending dead-key accent class global `g_deadkey_class (0x715b78) = 0`. This is the same byte that `deadkey_accent_classify` (FUN_00635500) writes (0-4, or 0xFF for none) and that `kbd_compose_accented_char` (FUN_006355a0) reads to combine an accent with a base letter. Setting it to 0 does NOT mean "none" (0 is the *circumflex* class, 0xFF is "none") — so this reset is used at points where the widget wants the accent state cleared to a known baseline (open, commit, cancel/back). One-line store.

Note: the prior name "reset_key_repeat" was imprecise — the byte at 0x715b78 is the dead-key accent class, not the pad auto-repeat timer (that state lives at kbd_state+0x1a/+0x1c, handled by pad_repeat_filter). Renamed to `reset_deadkey_state`.

## Input / output
- No params. Returns void.

## Side effects
- `*(u16*)0x715b78 = 0` (writes the accent-class global; the decompiler types the store as `uRam00715b78` = 0, but readers treat it as a byte `cRam00715b78`).

## Important branches
None (single store).

## Constants & flags
- `0x715b78` — dead-key accent class. Classes: 0=circumflex, 1=grave, 2=acute, 3=tilde, 4=diaeresis (see FUN_00635500); 0xFF=no pending accent. This function forces it to 0.

## Corrected reconstruction
```c
extern u8 g_deadkey_class;   // 0x715b78 (0..4 accent class, 0xFF=none)

void reset_deadkey_state(void)
{
    g_deadkey_class = 0;     // clear pending accent to baseline
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00634880.c` — `uRam00715b78 = 0;`.
- Cross-ref: FUN_00635500 writes 0x715b78 to 0-4/0xFF; FUN_006355a0 reads `cRam00715b78` (0-4) to pick the precomposed char. Same address ⇒ this is the accent class, not a repeat timer.
- Callers include open_name_entry and the accent-compose path (FUN_006355a0) which resets after committing a composed char.
- Runtime-unvalidated.

## Remaining uncertainty
- Store width: decompiler shows a u16/u32-ish `uRam` store to 0x715b78 but all readers use a single byte at that address; treated as byte here. Adjacent bytes at 0x715b79+ (if any) may also be zeroed by the wider store.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634880.c`  — untouched decompiler output.
