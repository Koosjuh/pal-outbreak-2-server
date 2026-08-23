# 0x005e9380 cfg_reset_addr_field

| field | value |
|---|---|
| Original address | 0x005e9380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9380 |
| Resolved name | cfg_reset_addr_field |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (config-directive dispatch table entry; 0 static callers)
**Callees:** FUN_005ef0e0 (apply/commit the previous field)
**Referenced globals:** 0x007012a0 (config block base); cfg+0x101c (0x101-byte address/proxy string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x101c

## Behavioral explanation
One handler in the connection-config directive family (siblings at 0x005e93c0 / 0x005e93f0, all
keyed on `0x7012a0 + 0x101c`). It first commits whatever field was being built via
`FUN_005ef0e0(param_2)`, then clears the 0x101-byte address/proxy string buffer at `cfg+0x101c`
so the next directive starts from an empty value. Behaves as the "reset / begin new address
entry" action of a small config parser (the config block at `0x7012a0` holds server host / proxy
settings consumed by the lobby connect pipeline).

## Input / output
- `param_1` (unused here).
- `param_2` (ptr): forwarded to `FUN_005ef0e0` (the value/context to commit before the reset).
- Returns `0` (ignored).

## Side effects
- `FUN_005ef0e0(param_2)` — applies/commits the pending field (side effects internal to that fn).
- `memset(cfg + 0x101c, 0, 0x101)` — zeroes the address/proxy string.

## Important branches
None — straight-line.

## Constants & flags
- `0x101` = buffer size (0x100 payload + NUL) of the `cfg+0x101c` address string.
- Field `cfg+0x101c` is later consumed by `FUN_005d9d70` (address/proxy apply) per the sibling
  handler notes.

## Corrected reconstruction
```c
// config block @0x7012a0: char addr_proxy[0x101] @ +0x101c; u8 auto_flag @ +0x111c; ...
u64 cfg_reset_addr_field(void *unused, void *commit_ctx)
{
    cfg_commit_pending(commit_ctx);          // FUN_005ef0e0
    memset(g_cfg /*0x7012a0*/ + 0x101c, 0, 0x101);  // clear addr/proxy string
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e9380.c` — one call + one memset(...,0,0x101).
- Shares `cfg+0x101c` with `parse_cfg_str_0x101c` (0x005e93c0); the three `0x005e93xx` handlers
  form a config-directive group. Zero static callers → dispatch-table entry (parser keyword table).
- Runtime-unvalidated.

## Remaining uncertainty
- What `FUN_005ef0e0` commits (which prior field) — glue not fully traced.
- The parser keyword/directive that selects this handler.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9380.c`  — untouched decompiler output.
