# 0x005e9790 textbuf_flush_if_pending_0x7f0

| field | value |
|---|---|
| Original address | 0x005e9790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9790 |
| Resolved name | textbuf_flush_if_pending_0x7f0 |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e97d0 (textbuf_begin_reset), FUN_005e9840 (textbuf_begin), FUN_005e9e20
**Callees:** FUN_005ede80 (textbuf_trim_and_commit)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x7f0 (pending flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0

## Behavioral explanation
Shared "flush the pending text block if one is open" helper for the multi-line text accumulator built
around `cfg+0x7f0` (open flag) / `cfg+0x7f1` (0x101-byte accumulation buffer). If a block is currently
open (`cfg+0x7f0 != 0`), it commits the accumulated content via FUN_005ede80 (trim + width-count +
copy into `cfg+0x7f1`) and clears the open flag. If no block is open it does nothing. Called at the
start of the two begin handlers (to finalize any prior block before starting a new one) and by
FUN_005e9e20.

Note: FUN_005ede80 is called here with NO argument (the register/arg is whatever is live), whereas the
end handler 0x005e98e0 passes an explicit text pointer. This flush path relies on FUN_005ede80's
internal read of the current accumulation state.

## Input / output
- `void` in / `void` out.

## Side effects
- When `cfg+0x7f0 != 0`: runs FUN_005ede80 (commits/trims into `cfg+0x7f1`, may bump max-width
  `cfg+0x18`, copies via FUN_005d92f0 gated by flags 0x186/0xe96b) and sets `cfg+0x7f0 = 0`.

## Important branches
- `if (cfg[0x7f0] != 0) { commit; cfg[0x7f0] = 0; }` — the single guard; no-op when unset.

## Constants & flags
- `cfg+0x7f0` — boolean "text block open / commit pending".

## Corrected reconstruction
```c
// flush the open multi-line text block, if any
void textbuf_flush_if_pending_0x7f0(void)
{
    if (cfg[0x7f0] != 0) {          // a block is open
        textbuf_trim_and_commit();  // FUN_005ede80 — trim + count + copy into cfg+0x7f1
        cfg[0x7f0] = 0;             // mark closed
    }
}
```

## Evidence
- Raw decompile: `if (cfg[0x7f0] != '\0') { FUN_005ede80(); cfg[0x7f0] = 0; }`.
- FUN_005ede80 read directly: leading-space skip (CTYPE bit 2), trailing SP/TAB trim, multibyte width
  count → `cfg+0x18`, then FUN_005d92f0 copy into `cfg+0x7f1` under flag guard.
- Runtime-unvalidated.

## Remaining uncertainty
- The exact live argument FUN_005ede80 consumes in the no-arg call (decompiler dropped it).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9790.c`  — untouched decompiler output.
