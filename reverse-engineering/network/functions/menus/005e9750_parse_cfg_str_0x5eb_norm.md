# 0x005e9750 cfg_key_str_0x5eb_unescape

| field | value |
|---|---|
| Original address | 0x005e9750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9750 |
| Resolved name | cfg_key_str_0x5eb_unescape |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value), FUN_005e82c0 (cfg_unescape)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x5eb (0x100-byte string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x5eb

## Behavioral explanation
Displayed-text keyword handler, twin of 0x005e9540 but targeting `cfg+0x5eb`. Reads the `=value`
(optionally `"quoted"`) token into `cfg+0x5eb`, then runs the in-place entity/escape decoder
(FUN_005e82c0). The unescape pass marks this as displayed prose (a second caption/label slot distinct
from the 0x3e4 one).

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes up to 0x100 bytes (NUL-terminated) to `cfg+0x5eb`, then unescapes in place.
- Advances `*cursor`.

## Important branches
- None locally; branching is in the callees (cfg_read_value `=`/quote/delimiter, cfg_unescape entity loop).

## Constants & flags
- `0x100` — field size.
- `cfg+0x5eb` — second caption/label string field (unescaped) [inferred].

## Corrected reconstruction
```c
// keyword handler: secondary caption text with entity unescape → cfg+0x5eb
uint64_t cfg_key_str_0x5eb_unescape(char **cursor)
{
    cfg_read_value(cursor, &cfg[0x5eb], 0x100);   // FUN_005ec1b0
    cfg_unescape(&cfg[0x5eb]);                      // FUN_005e82c0
    return 0;
}
```

## Evidence
- Raw decompile: `FUN_005ec1b0(param_1, cfg+0x5eb, 0x100)` then `FUN_005e82c0(cfg+0x5eb)`.
- Identical structure to FUN_005e9540 (the 0x3e4 caption handler).
- Runtime-unvalidated.

## Remaining uncertainty
- Which displayed slot 0x5eb feeds (e.g. secondary/help text vs. alternate label); downstream reader not mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9750.c`  — untouched decompiler output.
