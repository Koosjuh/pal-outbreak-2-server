# 0x005e8530 tag_sound_cmd

| field | value |
|---|---|
| Original address | 0x005e8530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8530 |
| Resolved name | tag_inline_command |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005ec1b0 (extract `="..."` attribute value), FUN_005d8aa0 (command dispatch)
**Referenced globals:** iRam007012a0+0x186 (measure_only), +0xe96b (silent)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** ctx+0x186; ctx+0xe96b

## Behavioral explanation
Argument-taking markup tag. It parses the tag's `="..."` inline value out of the markup source
into a 256-byte stack buffer via `FUN_005ec1b0` (the attribute-value extractor: it scans for
`=` then `"`, copies until the closing quote, handling multi-byte high-bit sequences and
advancing the source cursor `*param_1` past the value). It then dispatches that string as a
command to `FUN_005d8aa0` — but only when NOT in a non-emitting pass: the dispatch is gated on
both `ctx+0x186 == 0` (measure-only / layout-sizing pass) and `ctx+0xe96b == 0` (silent pass).
This gating is exactly the pattern for a *side-effecting* tag (sound/effect/script trigger)
that must fire once during real rendering but be suppressed while the engine is only measuring
text extent or replaying silently.

## Input / output
- `param_1` (undefined8 → uint32*): pointer to the markup source cursor; advanced past the consumed `="..."` value by `FUN_005ec1b0`.
- returns 0.
- No `param_2` accumulator here — this tag does not flush glyphs; it only consumes an inline argument and (maybe) fires a command.

## Side effects
- `FUN_005ec1b0(param_1, buf, 0x100)` advances `*param_1` (source cursor) past the attribute value; fills local `buf[256]`.
- When `ctx+0x186 == 0 && ctx+0xe96b == 0`: `FUN_005d8aa0(buf)` — dispatches the extracted command string (audio/effect/script) [inferred target role].

## Important branches
- `ctx+0x186 == '\0' && ctx+0xe96b == '\0'` → **fire** the command. Either flag non-zero → suppress (measure-only or silent pass); the value is still consumed from the stream so parsing stays aligned.

## Constants & flags
- `ctx+0x186` — `measure_only`: layout-sizing pass, suppress side effects.
- `ctx+0xe96b` — `silent`: suppress audible/visible side effects.
- Local buffer size `0x100` (256 bytes) — max extracted argument length.

## Corrected reconstruction
```c
// A markup tag with an ="..." argument that triggers an engine command (sound/effect).
// Suppressed during measure-only or silent layout passes.
undefined8 tag_inline_command(uint32_t *src_cursor)
{
    char arg[256];
    attr_extract_quoted(src_cursor, arg, sizeof arg);   // FUN_005ec1b0: parse ="...", advance cursor
    if (g_txtctx->measure_only == 0 && g_txtctx->silent == 0)
        engine_command_dispatch(arg);                   // FUN_005d8aa0 [inferred: audio/effect]
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8530.c`.
- `FUN_005ec1b0` (read): a `=`→`"`→copy-until-`"` state machine with high-bit multibyte handling and `param_3`-bounded output that writes `*param_1 = cursor` on exit — an attribute-value extractor.
- The double-flag suppression (`+0x186`, `+0xe96b`) is the canonical guard for one-shot side effects during measure/silent passes.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- `FUN_005d8aa0` not decompiled — "sound/effect command" is inferred from the guarded, string-argument, non-glyph shape; could be any engine command (BGM, SE, script, portrait).
