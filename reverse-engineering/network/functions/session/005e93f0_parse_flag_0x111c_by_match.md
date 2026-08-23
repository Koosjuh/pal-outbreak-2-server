# 0x005e93f0 cfg_set_flag_0x111c_on_match

| field | value |
|---|---|
| Original address | 0x005e93f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e93f0 |
| Resolved name | cfg_set_flag_0x111c_on_match |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (config-directive dispatch table entry; 0 static callers)
**Callees:** FUN_005ec320 (bounded token extract), func_0x0010a338 (memcmp, 4 bytes) [lib thunk]
**Referenced globals:** 0x007012a0 (config block base); cfg+0x111c (u8 boolean flag)
**Referenced strings:** 0x648518 (4-byte compare constant — literal bytes not captured in corpus)
**Referenced opcodes:** —
**State vars:** cfg+0x111c

## Behavioral explanation
Config-directive handler that conditionally sets a boolean flag in the connection-config block.
It extracts the directive's argument token into a 272-byte stack buffer, compares its first 4
bytes against the constant at `0x648518`, and on an exact match sets `cfg + 0x111c = 1`. This is
the classic keyword→boolean toggle of a small config parser (e.g. an "enable proxy/auto" style
switch). The flag it sets gates whether the address/proxy string at `cfg+0x101c` (set by the
sibling handler 0x005e93c0) is actually applied by the connect pipeline. A non-matching argument
leaves the flag untouched (defaults off).

## Input / output
- `param_1` (ptr): parse context / source token pointer.
- Returns `0` (ignored).

## Side effects
- `cfg + 0x111c = 1` **only if** the 4-byte prefix of the argument matches `*0x648518`.
- Uses a 272-byte (`0x110`) stack scratch buffer; no heap/global writes besides the flag.

## Important branches
- `memcmp(token, *0x648518, 4) == 0` → `*(u8*)(cfg+0x111c) = 1`.
- else → no write (flag retains prior value).

## Constants & flags
- `cfg+0x111c` = u8 boolean (0/1) gating the `cfg+0x101c` address/proxy apply.
- `0x648518` = 4-byte comparison keyword (ASCII, e.g. an "ON"/"YES"-class token) — **exact bytes
  unresolved** (not present in the string dump).
- Copy bound `0x100` into a `0x110`-byte stack buffer.

## Corrected reconstruction
```c
u64 cfg_set_flag_0x111c_on_match(parse_ctx_t *p)
{
    char token[0x110];                             // auStack_110
    cfg_extract_token(p, token, 0x100);            // FUN_005ec320
    if (memcmp(token, KW_MATCH /*@0x648518, 4B*/, 4) == 0)
        *(u8*)(g_cfg /*0x7012a0*/ + 0x111c) = 1;   // enable flag
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e93f0.c` — token extract, `func_0x0010a338
  (buf, 0x648518, 4)` (memcmp), conditional `cfg+0x111c = 1`.
- `func_0x0010a338(a,b,n)` matches memcmp usage elsewhere in the overlay.
- Sibling of 0x005e93c0 (`cfg+0x101c` string) and 0x005e9380 (reset). Runtime-unvalidated.

## Remaining uncertainty
- The literal keyword bytes at `0x648518` (need a data dump of that address to confirm the token).
- That `0x111c` specifically gates the `0x101c` apply is inferred from the sibling grouping.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e93f0.c`  — untouched decompiler output.
