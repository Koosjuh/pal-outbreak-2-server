# 0x005e95e0 cfg_key_num_0x4e8_default256_clamp

| field | value |
|---|---|
| Original address | 0x005e95e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e95e0 |
| Resolved name | cfg_key_num_0x4e8_default256_clamp |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value), FUN_005ec650 (cfg_atoi)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x4e8 (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x4e8

## Behavioral explanation
Numeric keyword handler with default-and-clamp. Reads the `=value` token, parses decimal, stores u16 at
`cfg+0x4e8`. If the parsed value is 0 it substitutes 0x100 (256); if it exceeds 0x100 it is clamped down
to 0x100. Net effect: the stored value is always in `[1, 256]` after a nonzero parse, or exactly 256 when
zero/blank. The 256 default/ceiling matches a text/buffer capacity limit (twin numeric field to 0x4e6's
width; likely a max-length or max-count).

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes u16 at `cfg+0x4e8`, always in `[1,256]` (or 256 if input was 0).
- Advances `*cursor`.

## Important branches
- `if (v == 0) v = 0x100;` — zero → default 256.
- `else if (v > 0x100) v = 0x100;` — clamp to ceiling 256.
- (unsigned compare; values 1..256 pass through unchanged.)

## Constants & flags
- `0x100` (256) — both the default (when zero) and the maximum (clamp ceiling).

## Corrected reconstruction
```c
// keyword handler: max length/count → cfg+0x4e8, default & ceiling 256
uint64_t cfg_key_num_0x4e8_default256_clamp(char **cursor)
{
    char tmp[0x100];
    cfg_read_value(cursor, tmp, 0x100);
    uint16_t v = (uint16_t)cfg_atoi(tmp);            // FUN_005ec650
    *(uint16_t *)&cfg[0x4e8] = v;
    if (v == 0)              *(uint16_t *)&cfg[0x4e8] = 0x100;   // default 256
    else if (v > 0x100)      *(uint16_t *)&cfg[0x4e8] = 0x100;   // clamp 256
    return 0;
}
```

## Evidence
- Raw decompile: store at `cfg+0x4e8`; `if ==0 →0x100`; `else if 0x100 < v →0x100` (ushort compares).
- Runtime-unvalidated.

## Remaining uncertainty
- Precise meaning of the field (max characters vs. max entries). 256 ceiling ties it to a length/count.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e95e0.c`  — untouched decompiler output.
