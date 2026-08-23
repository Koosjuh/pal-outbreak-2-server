# 0x005e93c0 cfg_set_addr_field

| field | value |
|---|---|
| Original address | 0x005e93c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e93c0 |
| Resolved name | cfg_set_addr_field |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (config-directive dispatch table entry; 0 static callers)
**Callees:** FUN_005ec1b0 (bounded token copy)
**Referenced globals:** 0x007012a0 (config block base); cfg+0x101c (0x100-byte address/proxy string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x101c

## Behavioral explanation
Config-directive handler that stores the directive's argument string into the address/proxy field
`cfg + 0x101c`. It calls `FUN_005ec1b0(src, dst, 0x100)` — a bounded token copy that reads the
next token from the parse cursor `param_1` and writes up to 0x100 bytes into the field. This is
the "set address / proxy host" action, paired with the reset handler at 0x005e9380 (which clears
the same buffer) and the flag handler at 0x005e93f0 (which toggles `cfg+0x111c`). The value is
later consumed by the lobby connect pipeline when composing the server host string.

## Input / output
- `param_1` (ptr): parse context / source token pointer.
- Returns `0` (ignored).

## Side effects
- `FUN_005ec1b0(param_1, cfg+0x101c, 0x100)` — copies up to 0x100 bytes of the argument into the
  address/proxy string buffer.

## Important branches
None here (any bounds/termination handling is inside `FUN_005ec1b0`).

## Constants & flags
- `0x100` = max bytes copied into `cfg+0x101c` (buffer is 0x101 incl. NUL per the reset handler).

## Corrected reconstruction
```c
u64 cfg_set_addr_field(parse_ctx_t *p)
{
    cfg_copy_token(p, g_cfg /*0x7012a0*/ + 0x101c, 0x100);  // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e93c0.c` — single `FUN_005ec1b0(param_1,
  0x7012a0+0x101c, 0x100)` then `return 0`.
- Same field `cfg+0x101c` as the reset handler 0x005e9380; sibling of the 0x005e93f0 flag handler.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact copy/termination semantics of `FUN_005ec1b0` (assumed strncpy-like bounded token copy).
- Which config keyword selects this handler.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e93c0.c`  — untouched decompiler output.
