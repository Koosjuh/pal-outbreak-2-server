# 0x005e4af0 dialog_draw_noop

| field | value |
|---|---|
| Original address | 0x005e4af0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e4af0 |
| Resolved name | dialog_draw_noop |
| Subsystem | unknown |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dd660 (dialog-kind draw dispatcher)
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty function — a single `return`, no body. Its only caller FUN_005dd660 is the dialog
draw dispatcher that also calls the concrete dialog renderers FUN_005e4b00 (two-button),
FUN_005e4f10 (one-button), FUN_005e5200 (status), FUN_005e5650 (toggle). This no-op is the
"draw nothing" entry for a dialog-kind slot that has no visual (e.g. an invisible/spacer
dialog state, or a reserved table slot), keeping the dispatch table dense so the dialog-kind
byte can index directly without a gap check.

## Input / output
- Input: none observed (`void`; the dispatcher may pass an element pointer that is ignored).
- Output: none. No side effects.

## Side effects
- None.

## Important branches
- None.

## Constants & flags
- None.

## Corrected reconstruction
```c
// "Draw nothing" slot in the dialog-kind draw table (FUN_005dd660).
void dialog_draw_noop(void) { /* no-op */ }
```

## Evidence
- Raw decompile: 8-byte body, `return;` only, zero callees.
- Sole caller FUN_005dd660 is the same dispatcher that fans out to the four concrete
  dialog renderers — placing this as the empty/reserved dialog-kind handler. Runtime-unvalidated.

## Remaining uncertainty
- Whether the slot is truly "invisible dialog" vs a reserved/unused table entry cannot be
  distinguished from the body alone; confirming requires reading FUN_005dd660's dispatch table.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e4af0.c`  — untouched decompiler output.
