# 0x005e9710 cfg_key_num_0x6ee

| field | value |
|---|---|
| Original address | 0x005e9710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9710 |
| Resolved name | cfg_key_num_0x6ee |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value), FUN_005ec650 (cfg_atoi)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x6ee (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x6ee

## Behavioral explanation
Numeric keyword handler, structurally identical to 0x005e96d0 but targeting the adjacent u16 field
`cfg+0x6ee` (immediately after 0x6ec). Reads the `=value` token, decimal-parses it, stores the u16 raw
with no default or clamp. The two adjacent fields 0x6ec/0x6ee are a value pair (e.g. width/height or
min/max) consumed together by the layout code.

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes u16 at `cfg+0x6ee` (raw; blank/non-numeric → 0).
- Advances `*cursor`.

## Important branches
- None (raw store, twin of 0x005e96d0).

## Constants & flags
- `0x100` — scratch read size. No default.

## Corrected reconstruction
```c
// keyword handler: numeric pair partner of 0x6ec → cfg+0x6ee (raw)
uint64_t cfg_key_num_0x6ee(char **cursor)
{
    char tmp[0x100];
    cfg_read_value(cursor, tmp, 0x100);
    *(uint16_t *)&cfg[0x6ee] = (uint16_t)cfg_atoi(tmp);   // FUN_005ec650
    return 0;
}
```

## Evidence
- Raw decompile: identical shape to FUN_005e96d0, store at `cfg+0x6ee`.
- Adjacency of 0x6ec/0x6ee implies a paired numeric field.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether 0x6ec/0x6ee form width/height, min/max, or an unrelated pair; no direct reader mapped for 0x6ee.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9710.c`  — untouched decompiler output.
