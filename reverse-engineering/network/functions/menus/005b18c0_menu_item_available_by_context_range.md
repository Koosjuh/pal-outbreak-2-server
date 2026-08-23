# 0x005b18c0 input_is_content_key

| field | value |
|---|---|
| Original address | 0x005b18c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b18c0 |
| Resolved name | input_is_content_key (was: menu_item_available_by_context_range) |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4b80
**Callees:** —
**Referenced globals:** 0x6c4618 `g_padEdge`; 0x6c462a `g_softKey`
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4618; 0x6c462a

## Behavioral explanation
Predicate that answers "did the player press a *content* key this frame" — i.e. a real selectable/typeable input rather than a navigation control (d-pad / shoulder). Returns 1 immediately if pad bit `0x20` is set in `g_padEdge` (a dedicated confirm/select button). Otherwise it inspects the soft-key code `g_softKey` (0x6c462a): the code must fall inside one of three valid windows AND must not be one of the reserved navigation/shoulder codes; only then is it a content key. All nav codes ('(' ')' '*' '+', 0x39, 'I'..'R', 0x88, 0x8a) and out-of-window codes return 0.

This is the gate the single caller (0x5f4b80, a name-entry / soft-keyboard driver) uses to distinguish "commit a character" from "move the on-screen cursor".

## Input / output
- `void`.
- returns `undefined4` — 1 if a content/select key is active this frame, else 0.

## Side effects
None.

## Important branches
- `g_padEdge & 0x20` → return 1 (hard confirm button).
- code `< 4` OR in gaps `(0x39,0x49)` ∪ `(0x52,0x87)` ∪ `> 0x8b` → return 0 (outside valid windows).
- inside a window: `== 0x8b` → 0; `== 0x8a` → 0; if code is any of the reserved nav set {0x88,0x52..0x49,0x39,0x2b,0x2a,0x29,0x28} → 0; otherwise → 1.

## Constants & flags
- `0x20` — dedicated confirm/select pad bit.
- Valid soft-key windows: `[0x04..0x39] ∪ [0x49..0x52] ∪ [0x87..0x8b]`.
- Reserved (excluded, treated as navigation): `0x28`='(' `0x29`=')' `0x2a`='*' `0x2b`='+' `0x39` `0x49`='I'..`0x52`='R' `0x88` `0x8a` `0x8b`.

## Corrected reconstruction
```c
extern u32 g_padEdge;   // 0x6c4618
extern u8  g_softKey;   // 0x6c462a  (bRam006c462a)

// True when the current input is a "content" key (character/select),
// not a navigation control. Bit 0x20 = hard confirm button.
u32 input_is_content_key(void)
{
    if (g_padEdge & 0x20)
        return 1;

    u8 c = g_softKey;
    // outside the three valid code windows -> not a content key
    if (c < 4 || (c > 0x39 && c < 0x49) || (c > 0x52 && c < 0x87) || c > 0x8b)
        return 0;

    if (c == 0x8b) return 0;
    if (c == 0x8a) return 0;
    // reserved navigation / shoulder codes -> not content
    if (c == 0x88 || (c >= 0x49 && c <= 0x52) || c == 0x39 ||
        c == 0x2b || c == 0x2a || c == 0x29 || c == 0x28)
        return 0;
    return 1;
}
```
(The original spells the exclusion set out as an explicit `&&` chain of `!=` tests; it is equivalent to the range checks above for the codes reachable inside the windows.)

## Evidence
- Raw `FUN_005b18c0.c`: `uRam006c4618 & 0x20` fast-path (line 11); window bounds (lines 12–13); the long `!=` exclusion chain (lines 21–27) enumerating exactly the nav/shoulder codes.
- Excluded set = the navigation codes decoded in 0x5b14b0 ('(' ')' UP 'R' DOWN 'Q' etc.), confirming this filters nav vs content.
- Runtime-unvalidated.

## Remaining uncertainty
- The precise meaning of windows `[0x87..0x8b]` (likely analog/extended soft-keys) and codes 0x88/0x8a/0x8b is inferred.
- The `input_is_content_key` label is a semantic inference from the single caller's role; mechanics are certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b18c0.c`  — untouched decompiler output.
