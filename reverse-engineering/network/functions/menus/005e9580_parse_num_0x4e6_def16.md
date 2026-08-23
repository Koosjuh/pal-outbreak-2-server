# 0x005e9580 cfg_key_num_0x4e6_default16

| field | value |
|---|---|
| Original address | 0x005e9580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9580 |
| Resolved name | cfg_key_num_0x4e6_default16 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value), FUN_005ec650 (cfg_atoi)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x4e6 (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x4e6

## Behavioral explanation
Numeric keyword handler. Reads the `=value` token into a local scratch buffer, parses it as a decimal
integer, stores the low 16 bits at `cfg+0x4e6`, and substitutes the default `0x10` (16) when the parsed
value is zero (i.e. missing/blank/non-numeric). `cfg+0x4e6` is read back by the row-measure routine
FUN_005edc40 (cases 0/1) as the field width, so this is a column/field width in characters, default 16.

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes u16 at `cfg+0x4e6`.
- Advances `*cursor`.
- Local 272-byte stack buffer only (not retained).

## Important branches
- `if (cfg.u16[0x4e6] == 0) cfg.u16[0x4e6] = 0x10;` — zero → default 16. This is the sole branch.
- `cfg_atoi` accumulates only ASCII `'0'..'9'`; any non-digit content yields 0 → triggers the default.

## Constants & flags
- `0x10` (16) — default width when unset/zero.
- `0x100` — scratch read size.

## Corrected reconstruction
```c
// keyword handler: field width (chars) → cfg+0x4e6, default 16
uint64_t cfg_key_num_0x4e6_default16(char **cursor)
{
    char tmp[0x100];                         // auStack_110[272], 0x100 used
    cfg_read_value(cursor, tmp, 0x100);      // FUN_005ec1b0
    *(uint16_t *)&cfg[0x4e6] = (uint16_t)cfg_atoi(tmp);   // FUN_005ec650
    if (*(int16_t *)&cfg[0x4e6] == 0)
        *(uint16_t *)&cfg[0x4e6] = 0x10;     // default 16
    return 0;
}
```

## Evidence
- Raw decompile: read into `auStack_110`, `FUN_005ec650`, store at `cfg+0x4e6`, zero→0x10.
- FUN_005ec650 confirmed as decimal atoi (loops strlen chars, `bVar1-0x30` on `'0'..'9'`).
- Width role inferred from FUN_005edc40 cases 0/1 using `cfg+0x4e6` as `sVar7` (measured width).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether the u16 is truly a character width vs. some other count in the type-0/1 layout path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9580.c`  — untouched decompiler output.
