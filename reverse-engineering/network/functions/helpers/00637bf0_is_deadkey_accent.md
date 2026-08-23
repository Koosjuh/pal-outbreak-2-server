# 0x00637bf0 is_deadkey_accent

| field | value |
|---|---|
| Original address | 0x00637bf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637bf0 |
| Resolved name | is_ascii_base_no_pending_accent |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_006379e0
**Callees:** FUN_00635500
**Referenced globals:** — (dead-key state is read inside FUN_00635500)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accent-composition gate for the software keyboard. Returns **true** only when there is no pending
dead-key accent (`FUN_00635500()` returns -1 = "none") **and** the input glyph is plain 7-bit ASCII
(`< 0x80`). In the page-5 (accent) branch of `kbd_key_allowed_for_page`, a *false* result (accent
pending, or a non-ASCII base char) is what unlocks the accent glyph — i.e. the accent page shows
composed characters only while a dead-key is armed or the base is non-ASCII.

## Input / output
- `param_1` — `u16` candidate glyph.
- **Returns** `bool` — true iff `FUN_00635500() == -1 && param_1 < 0x80`.

## Side effects
None (FUN_00635500 is a read of the pending dead-key state).

## Important branches
- `FUN_00635500() != -1` (a dead-key accent is armed) -> false.
- glyph `>= 0x80` (non-ASCII) -> false.
- otherwise -> true.

## Constants & flags
- `-1` — sentinel from FUN_00635500 meaning "no pending dead-key". [inferred]
- `0x80` — ASCII/non-ASCII boundary.

## Corrected reconstruction
```c
// true = plain ASCII base char with no dead-key accent pending.
bool is_ascii_base_no_pending_accent(u16 cp)
{
    char pending = FUN_00635500();   // -1 = no dead-key armed
    return pending == -1 && cp < 0x80;
}
```

## Notes / uncertainty
FUN_00635500's -1 sentinel semantics ("no pending accent") inferred from usage, not opened. Renamed
from `is_deadkey_accent` to `is_ascii_base_no_pending_accent` to match the actual (inverted) meaning.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637bf0.c`  — untouched decompiler output.

## Evidence
- Raw: `cVar1 = FUN_00635500(); return cVar1 == -1 && param_1 < 0x80;`. Runtime unvalidated.
