# 0x005e9c30 menu_row_commit_default_0x2d3

| field | value |
|---|---|
| Original address | 0x005e9c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9c30 |
| Resolved name | menu_row_commit_default_0x2d3 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ef200 (save/prologue — opaque), FUN_005ef220 (menu_commit_row), func_0x00109eb8 (strcpy)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x2d3 (0x10 flag-string field)
**Referenced strings:** 0x648520 (default constant string)
**Referenced opcodes:** —
**State vars:** cfg+0x2d3

## Behavioral explanation
Commits a menu row using the DEFAULT value for the `cfg+0x2d3` flag field. It runs the row prologue
FUN_005ef200 (a save/context routine Ghidra decodes as `halt_baddata` — likely a hand-written stub or
mis-disassembled save-regs), copies the hard-coded default string at 0x648520 into `cfg+0x2d3`, then
calls FUN_005ef220 (menu_commit_row) which latches the row's value/flag from `cfg+0x2c3`/`cfg+0x2d3`
into the current row slot and advances the row index. In FUN_005ef220, `cfg+0x2d3` is decoded via
FUN_005ec800 to a per-row byte flag; supplying the default string here yields the default flag for
rows that omit that attribute. This is the "no attribute given → use default, then commit row" path;
the twin parse handler (referenced as ~0x9cd0) instead fills `cfg+0x2d3` from the config token.

## Input / output
- `void` in. Returns `0`.

## Side effects
- `strcpy(cfg+0x2d3, "…"@0x648520)` — sets the flag field to its default.
- FUN_005ef220: clamps row index `cfg+0x124` (≤0xE/14), writes row value (`cfg+0x2c3` via FUN_005ec4f0,
  default from `cfg+0x128` when blank/negative), writes row flag (`cfg+0x2d3` via FUN_005ec800),
  increments `cfg+0x124` if < 14, and calls FUN_005ec100.
- FUN_005ef200: opaque prologue/context save (no observable field writes reconstructed).

## Important branches
- None locally. Branching (index clamp, blank/negative value fallback, flag decode) is inside FUN_005ef220.

## Constants & flags
- `0x648520` — default flag string copied into `cfg+0x2d3`.
- `cfg+0x2d3` — per-row flag string field (0x10 bytes; decoded to a byte by FUN_005ec800).
- Row index ceiling `0xE` (14) in FUN_005ef220.

## Corrected reconstruction
```c
// commit a menu row using the DEFAULT 0x2d3 flag value
uint64_t menu_row_commit_default_0x2d3(void)
{
    menu_row_prologue();                        // FUN_005ef200 (opaque save/context)
    strcpy(&cfg[0x2d3], /* @0x648520 */ kDefaultRowFlag);  // func_0x00109eb8
    menu_commit_row();                          // FUN_005ef220
    return 0;
}
```

## Evidence
- Raw decompile: FUN_005ef200(); func_0x00109eb8(cfg+0x2d3, 0x648520); FUN_005ef220().
- FUN_005ef220 read directly: uses `cfg+0x2c3` (value, FUN_005ec4f0) and `cfg+0x2d3` (flag,
  FUN_005ec800), index clamp at 0xE, `cfg+0x124` increment.
- FUN_005ef200 decodes as `halt_baddata` (bad-instruction) — treated as opaque prologue.
- Runtime-unvalidated.

## Remaining uncertainty
- The literal content/meaning of the 0x648520 default string (not dereferenced here).
- FUN_005ef200's true behavior (opaque). The "twin parse handler" address (~0x9cd0) is inferred by pattern.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9c30.c`  — untouched decompiler output.
