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
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0 (softkbd input dispatcher), FUN_00634ab0
**Callees:** FUN_006352e0 (commit field value), FUN_00633430 (advance conversion candidate), FUN_00633470 (start IME conversion), FUN_00633930 / FUN_00633ab0 (candidate-list cycle), FUN_00630c50 (state predicate)
**Referenced globals:** iRam00715da8 (SoftKbd widget-state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x08 active-field object ptr; +0x2f IME state; +0x30 widget mode; +0x248 result code; +0x260 IME composition buffer

## Behavioral explanation
Handles the "confirm / enter" key (raw dispatch key 0x2c) of the on-screen software keyboard IME. It reads the IME composition state (`+0x2f`) and either advances the kanji-conversion candidate selection, confirms the pending composition into the target field, or (when nothing is composing) commits the current field value. `param_1` selects between confirm (0) and step-to-next-candidate (non-zero).

## Input / output
- `long param_1` — action selector: `0` = confirm/accept current candidate or field; non-zero = advance to next conversion candidate. [inferred: 0=OK-press, 1=cycle]
- Returns `void`. Effective output is the posted result code at `+0x248` (0/1) and mutations performed by the callees.

## Side effects
- May call `commit_field(+0x08)` (FUN_006352e0) — writes the accepted string back to the active input-field object.
- May advance/redraw the IME conversion candidate list (FUN_00633430 / FUN_00633930 / FUN_00633ab0 / FUN_00633470).
- Sets `+0x248 = 1` (KBRES_REDRAW/commit) when widget mode `+0x30 == 1`.

## Important branches
- `ime_state == 2 || 3` (converting/selecting): if `param_1==0` -> `commit_field(field_ptr)`; else -> `advance_candidate()`. Then if `mode==1` -> result=1.
- `ime_state == 1` (composing): result implicitly not set here; if `state_predicate()==0` -> `candidate_open_A()` (FUN_00633ab0) else `candidate_open_B()` (FUN_00633930).
- `ime_state == 0` (idle): if IME buffer empty (`+0x260==0`) and `param_1==0` -> `commit_field()`, and if `mode==1` result=1. If IME buffer NON-empty -> `ime_convert_start()` (FUN_00633470).

## Constants & flags
- `+0x2f` IME state enum: `0` idle, `1` composing, `2` converting, `3` selecting-candidate. [inferred from branch structure]
- `+0x30` widget mode: `1` = commit-capable (single-line OK) mode. [inferred]
- `+0x248` result: `1` = redraw/commit posted.

## Corrected reconstruction
```c
enum ImeState { IME_IDLE=0, IME_COMPOSING=1, IME_CONVERTING=2, IME_SELECTING=3 };
enum KbResult { KBRES_NAV=0, KBRES_REDRAW=1, KBRES_CANCEL=2, KBRES_BLOCKED=5 };

// key 0x2c: confirm / next-candidate
void softkbd_ime_confirm_key(long advance /*0=confirm,!=0=next*/)
{
    SoftKbd *kb = (SoftKbd*)iRam00715da8;
    char st = kb->ime_state;                      // +0x2f

    if (st == IME_CONVERTING || st == IME_SELECTING) {
        if (advance == 0)
            commit_field(kb->field_ptr);          // FUN_006352e0(+0x08)
        else
            ime_advance_candidate();              // FUN_00633430
        if (kb->mode == 1)                        // +0x30
            kb->result = KBRES_REDRAW;            // +0x248 = 1
    }
    else if (st == IME_COMPOSING) {
        kb->result = KBRES_NAV;                   // +0x248 = 0
        if (ime_state_predicate() == 0)           // FUN_00630c50
            ime_candidate_open_a();               // FUN_00633ab0
        else
            ime_candidate_open_b();               // FUN_00633930
    }
    else if (st == IME_IDLE) {
        if (kb->ime_buf[0] == 0) {                // +0x260 == 0 (empty composition)
            if (advance == 0) {
                commit_field(kb->field_ptr);      // FUN_006352e0(+0x08)
                if (kb->mode == 1)
                    kb->result = KBRES_REDRAW;
            }
        } else {
            ime_convert_start();                  // FUN_00633470
        }
    }
}
```

## Evidence
- Raw decompile branch tree on `*(char*)(iRam00715da8+0x2f)` values 3/2/1/0.
- Callers FUN_006300a0 (the per-key dispatcher) and FUN_00634ab0 confirm this is a keypress handler.
- Callee FUN_006352e0 receives `+0x08` (the field object ptr) = "write value into field".
- Result-code semantics (0/1/2/5) inferred consistently across the whole softkbd handler family (this task's 16 functions).

## Remaining uncertainty
- Exact meaning of `param_1` (confirm vs next) and the IME-state enum labels are inferred from control flow, not runtime-traced.
- FUN_00633430/33470/33930/33ab0 candidate-list internals not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630f20.c` — untouched decompiler output.
