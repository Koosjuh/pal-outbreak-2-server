# 0x005e84b0 tag_newline_a

| field | value |
|---|---|
| Original address | 0x005e84b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e84b0 |
| Resolved name | tag_newline |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005ef040 (flush-run + line-feed)
**Referenced globals:** iRam007012a0 (via callee)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** — (delegates all state to FUN_005ef040)

## Behavioral explanation
Markup tag handler for a hard newline. It commits any pending glyph run and advances the pen
to the next line by delegating entirely to `FUN_005ef040`, the "flush + line-feed" primitive.
`FUN_005ef040` commits the staged run into the current page's layout buffer
(`ctx+0x1540 + page*4`), calls the line-advance helper `FUN_005eed40`, resets the pen origin
marker (`FUN_005ec170(ctx+0xd8bc)`), clears `pending_run_len` (`ctx+4`) and empties the
accumulator. In measure-only mode (`ctx+0xd892 != 0`) `FUN_005ef040` instead routes to
`FUN_005f3bc0` (measure-path line advance).

## Input / output
- `param_1` (undefined8): source/markup cursor handle — unused (this tag takes no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — passed straight to the flusher.
- returns 0.

## Side effects
All via `FUN_005ef040(param_2)`: layout-buffer append, line advance, pen reset, run-length = 0,
`*param_2 = 0`.

## Important branches
None in this function. (The measure/normal split lives inside `FUN_005ef040` on `ctx+0xd892`.)

## Constants & flags
None local.

## Corrected reconstruction
```c
// Emit a hard newline: flush the staged glyph run and line-feed the pen.
undefined8 tag_newline(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_and_linefeed(run_acc);   // FUN_005ef040
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e84b0.c` — single call + `return 0`.
- `FUN_005ef040` (read): flush primitive that appends to layout buffer, calls line-advance `FUN_005eed40`, resets pen and `pending_run_len`; measure path `FUN_005f3bc0`.
- Byte-for-byte identical to `FUN_005e84d0` (`tag_newline_b`) — the dispatch table binds two tag codes to the same behavior.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Which literal markup byte/escape maps to this handler vs. the twin `0x005e84d0` (dispatch table not dumped here).
