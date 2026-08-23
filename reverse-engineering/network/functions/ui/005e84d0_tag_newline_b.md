# 0x005e84d0 tag_newline_b

| field | value |
|---|---|
| Original address | 0x005e84d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e84d0 |
| Resolved name | tag_newline_alt |
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
**State vars:** — (delegates to FUN_005ef040)

## Behavioral explanation
Second markup tag code bound to the identical hard-newline behavior as `0x005e84b0`
(`tag_newline`): flush the pending glyph run and line-feed the pen via `FUN_005ef040`. Two
distinct tag bytes almost certainly map to the same primitive (e.g. `\n` and an explicit
`<br>`-style escape, or CR vs LF), which is why the compiler emitted two separate one-line
thunks rather than sharing an address.

## Input / output
- `param_1` (undefined8): markup cursor — unused (no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to the flusher.
- returns 0.

## Side effects
Via `FUN_005ef040(param_2)`: layout append, line advance (`FUN_005eed40`), pen reset, run-length
cleared, accumulator emptied. Measure-mode path `FUN_005f3bc0` (guarded by `ctx+0xd892`).

## Important branches
None local (measure/normal split is inside `FUN_005ef040`).

## Constants & flags
None local.

## Corrected reconstruction
```c
// Alternate newline tag — identical to tag_newline (0x005e84b0).
undefined8 tag_newline_alt(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_and_linefeed(run_acc);   // FUN_005ef040
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e84d0.c` — one call + `return 0`, byte-identical to `FUN_005e84b0`.
- Shared flush primitive `FUN_005ef040` documented under `tag_newline`.
- UI-only. Runtime-unvalidated.

## Remaining uncertainty
- The specific markup byte that dispatches here vs. the twin at `0x005e84b0`.
