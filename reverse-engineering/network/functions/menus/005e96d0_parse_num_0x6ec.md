# 0x005e96d0 cfg_key_num_0x6ec

| field | value |
|---|---|
| Original address | 0x005e96d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e96d0 |
| Resolved name | cfg_key_num_0x6ec |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value), FUN_005ec650 (cfg_atoi)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x6ec (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x6ec

## Behavioral explanation
Numeric keyword handler with NO default or clamp. Reads the `=value` token, parses decimal, stores the
u16 verbatim at `cfg+0x6ec`. This field is read by the row-measure routine FUN_005edc40 in the type-7
(and type-6 fall-through) branch as the row width `sVar7`, so `cfg+0x6ec` is the explicit width used by
those field types.

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes u16 at `cfg+0x6ec` (any value 0..65535; blank/non-numeric → 0).
- Advances `*cursor`.

## Important branches
- None. (Contrast with 0x5e9580/0x5e95e0 which apply default/clamp; this one stores raw.)

## Constants & flags
- `0x100` — scratch read size. No default constant (raw store).

## Corrected reconstruction
```c
// keyword handler: type-6/7 row width → cfg+0x6ec (raw, no default)
uint64_t cfg_key_num_0x6ec(char **cursor)
{
    char tmp[0x100];
    cfg_read_value(cursor, tmp, 0x100);
    *(uint16_t *)&cfg[0x6ec] = (uint16_t)cfg_atoi(tmp);   // FUN_005ec650
    return 0;
}
```

## Evidence
- Raw decompile: read scratch, `FUN_005ec650`, store `cfg+0x6ec`, no post-processing branch.
- Width role from FUN_005edc40 type-7 branch (`sVar7 = cfg[0x6ec]`).
- Runtime-unvalidated.

## Remaining uncertainty
- The keyword name and the exact field-type(s) that use `cfg+0x6ec` beyond the type-7 measure path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e96d0.c`  — untouched decompiler output.
