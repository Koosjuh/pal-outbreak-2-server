# 0x005e96a0 cfg_key_str_0x4eb_raw

| field | value |
|---|---|
| Original address | 0x005e96a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e96a0 |
| Resolved name | cfg_key_str_0x4eb_raw |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x4eb (0x100-byte string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x4eb

## Behavioral explanation
Plain string keyword handler. Reads the `=value` (optionally `"quoted"`) token into the string field at
`cfg+0x4eb` and returns. Unlike 0x005e9540/0x005e9750 it does NOT run the entity-unescape pass, so
`cfg+0x4eb` stores the raw parsed value verbatim — consistent with an identifier / filename / key token
rather than displayed prose.

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes up to 0x100 bytes (NUL-terminated) to `cfg+0x4eb`.
- Advances `*cursor`.

## Important branches
- None locally; see cfg_read_value for the `=`/quote/delimiter handling and the `dst_size-3` cap.

## Constants & flags
- `0x100` — field size.
- `cfg+0x4eb` — raw string field (no unescape) [inferred: identifier/name].

## Corrected reconstruction
```c
// keyword handler: raw string (no unescape) → cfg+0x4eb
uint64_t cfg_key_str_0x4eb_raw(char **cursor)
{
    cfg_read_value(cursor, &cfg[0x4eb], 0x100);   // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw decompile: single `FUN_005ec1b0(param_1, cfg+0x4eb, 0x100)`, return 0.
- Absence of an FUN_005e82c0 call distinguishes it from the unescaped caption handlers.
- Runtime-unvalidated.

## Remaining uncertainty
- Semantic role of `cfg+0x4eb` (identifier vs. path vs. other) unknown; no downstream reader mapped yet.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e96a0.c`  — untouched decompiler output.
