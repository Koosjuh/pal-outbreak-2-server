# 0x00635900 kbd_key_enabled_or_fail

| field | value |
|---|---|
| Original address | 0x00635900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635900 |
| Resolved name | kbd_key_blocked_check |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006352e0, FUN_006353e0
**Callees:** FUN_006379e0
**Referenced globals:** 0x715da8 (kbd state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x248 status

## Behavioral explanation
Guard used before committing a character. It calls the underlying key/length predicate `FUN_006379e0` (returns 1 when the input must be blocked — e.g. field is full / key disallowed). If blocked (`==1`), it sets the widget status `+0x248 = 5` (reject/error code, drives a beep in kbd_input_tick) and returns **false** (`lVar1 != 1` is false). If not blocked, it returns **true**, meaning "OK to proceed".

So the return is a positive "proceed" boolean: `true` = key allowed, `false` = blocked (and status already set to 5). Callers use it as `if (kbd_key_blocked_check()) proceed;` (FUN_006352e0 checks `== 1`), or early-return on false (FUN_006353e0).

## Input / output
- No params.
- Returns (bool) — `true` if the key may proceed, `false` if blocked (`FUN_006379e0() == 1`).

## Side effects
- On blocked: `+0x248 = 5` (reject status → feedback tone).

## Important branches
- `FUN_006379e0() == 1` (blocked) → `+0x248 = 5`, return false.
- else → return true.

## Constants & flags
- `+0x248 = 5` — reject/error status code (same code kbd_input_tick maps to `func_0x001b0140` feedback).
- Predicate convention: `FUN_006379e0` returns 1 = "blocked/full".

## Corrected reconstruction
```c
// Returns true when the key may proceed; false (and status=5) when blocked/full.
bool kbd_key_blocked_check(void)
{
    kbd_state *s = (kbd_state*)g_kbd_state;
    long blocked = FUN_006379e0();      // 1 = must block (full / disallowed)
    if (blocked == 1)
        s->status /*+0x248*/ = 5;       // reject -> feedback tone
    return blocked != 1;                // true = OK to proceed
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00635900.c` — `lVar1=FUN_006379e0(); if(lVar1==1) +0x248=5; return lVar1 != 1;`.
- Caller FUN_006352e0 gates accent-compose on `== 1`; FUN_006353e0 early-returns on `== 0`.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact predicate inside FUN_006379e0 (length-full vs key-disabled vs both) not reconstructed; the block/allow contract is certain.
- Prior name "kbd_key_enabled_or_fail" reversed the sense; renamed to `kbd_key_blocked_check` for clarity (return is "proceed", but the underlying test is "blocked").

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635900.c`  — untouched decompiler output.
