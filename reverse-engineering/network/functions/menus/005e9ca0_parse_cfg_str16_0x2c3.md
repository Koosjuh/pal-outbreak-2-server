# 0x005e9ca0 cfg_key_str16_0x2c3

| field | value |
|---|---|
| Original address | 0x005e9ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9ca0 |
| Resolved name | cfg_key_str16_0x2c3 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x2c3 (0x10-byte string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x2c3

## Behavioral explanation
Short-string keyword handler. Reads the `=value` token into the 16-byte field `cfg+0x2c3` (note the
0x10 size vs. 0x100 for the caption fields — this is a small token). `cfg+0x2c3` is later consumed by
the row-commit routine FUN_005ef220: when non-empty it is decoded via FUN_005ec4f0 into a signed row
value (falling back to the inherited default `cfg+0x128` when the decode is negative). So `cfg+0x2c3`
holds the row's value/index token (e.g. a numeric or symbolic id) that becomes the committed row value.

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes up to 0x10 bytes (NUL-terminated; reader's `-3` guard → ≤0xD payload) to `cfg+0x2c3`.
- Advances `*cursor`.

## Important branches
- None locally; see cfg_read_value. Downstream interpretation (decode/fallback) is in FUN_005ef220.

## Constants & flags
- `0x10` (16) — field size (small token, not a caption).
- `cfg+0x2c3` — row value/index token, decoded by FUN_005ec4f0 at commit [inferred from FUN_005ef220].

## Corrected reconstruction
```c
// keyword handler: 16-byte row value token → cfg+0x2c3
uint64_t cfg_key_str16_0x2c3(char **cursor)
{
    cfg_read_value(cursor, &cfg[0x2c3], 0x10);   // FUN_005ec1b0, note 16-byte cap
    return 0;
}
```

## Evidence
- Raw decompile: single `FUN_005ec1b0(param_1, cfg+0x2c3, 0x10)`.
- Role from FUN_005ef220: `if (cfg[0x2c3] != 0) { v = FUN_005ec4f0(cfg+0x2c3); if (v<0) fallback; }`
  writing the row value at `cfg+0x124*4 + 300`.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether the token is numeric-only (FUN_005ec4f0 = signed parse) or a symbolic lookup; not confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9ca0.c`  — untouched decompiler output.
