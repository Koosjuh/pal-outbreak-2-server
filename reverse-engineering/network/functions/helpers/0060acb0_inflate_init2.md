# 0x0060acb0 inflate_init2

| field | value |
|---|---|
| Original address | 0x0060acb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060acb0 |
| Resolved name | inflate_init2 (inflateInit2_) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060ae20
**Callees:** FUN_00608b70 (inflate_blocks_new), FUN_0060abc0 (inflate_reset), FUN_0060ac30 (inflate_end), thunk_FUN_0060c0f0 (default zalloc @0x0060bfe0), LAB_0060bff0 (default zfree), FUN_0060be50 (adler32 check func)
**Referenced globals:** 0x0064a260 version-str "1.1.4"
**Referenced strings:** 1.1.4
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib `inflateInit2_`. The library entry point that builds the inflate state. It (1) checks the caller
was compiled against the same zlib version (first byte of "1.1.4") and passed `sizeof(z_stream)==0x48`;
(2) installs default ZALLOC/ZFREE if the caller left them NULL; (3) allocates the 0x28-byte
internal_state; (4) interprets `windowBits` — negative means raw DEFLATE (`nowrap=1`, magnitude used) —
and validates the range 8..15; (5) allocates the block layer with `inflate_blocks_new` (window size
`1<<windowBits`, and passes the adler32 check function `FUN_0060be50` unless nowrap); (6) calls
`inflate_reset`. Any allocation failure rolls back via `inflate_end`. This function's version string
"1.1.4" is what fixes the whole decompression cluster as **zlib 1.1.4**.

**z_stream:** `+0x20 msg`, `+0x24 state`, `+0x28 zalloc`, `+0x2c zfree`, `+0x30 opaque`.
**internal_state (0x28):** `+0x00 mode`, `+0x18 nowrap`, `+0x1c wbits`, `+0x20 blocks`.

## Input / output
- **Params:**
  - `long param_1` — `z_streamp z`.
  - `uint param_2` — `int windowBits` (negative → raw/nowrap).
  - `long param_3` — `const char *version` (must start with '1').
  - `long param_4` — `int stream_size` (must == 0x48).
- **Return:** `undefined4`:
  - `0xfffffffa` (-6) Z_VERSION_ERROR — version mismatch or wrong stream_size.
  - `0xfffffffe` (-2) Z_STREAM_ERROR — NULL stream / bad windowBits.
  - `0xfffffffc` (-4) Z_MEM_ERROR — allocation failure.
  - `0` Z_OK.

## Side effects
- `z->msg (+0x20) = NULL`.
- Installs defaults: `z->zalloc = zcalloc (0x0060c0f0)`, `z->opaque = 0` if zalloc was NULL;
  `z->zfree = zcfree (0x0060bff0)` if zfree was NULL.
- Allocates `z->state (+0x24)` (0x28 bytes); sets `state->blocks (+0x20)=0`, `state->nowrap (+0x18)=0`.
- If `windowBits < 0`: `windowBits = -windowBits`, `state->nowrap = 1`.
- `state->wbits (+0x1c) = windowBits`.
- `state->blocks = inflate_blocks_new(z, nowrap ? NULL : adler32_checkfn(0x60be50), 1<<windowBits)`.
- `inflate_reset(z)` on success.
- On any alloc failure: `inflate_end(z)`.

## Important branches
- `version==NULL || version[0] != '1' || stream_size != 0x48` → return Z_VERSION_ERROR(-6).
- `z == NULL` → return Z_STREAM_ERROR(-2).
- `z->zalloc == NULL` → install default zalloc + opaque=0.
- `z->zfree == NULL` → install default zfree.
- state ZALLOC fails → return Z_MEM_ERROR(-4).
- `windowBits < 0` → nowrap=1, magnitude.
- `windowBits < 8 || windowBits > 15` → `inflate_end(z)`, return Z_STREAM_ERROR(-2).
- `inflate_blocks_new` returns NULL → `inflate_end(z)`, return Z_MEM_ERROR(-4).
- else → `inflate_reset(z)`, return Z_OK(0).

## Constants & flags
- `0x48` — required `sizeof(z_stream)`.
- `0x28` — sizeof(internal_state).
- windowBits valid range **8..15**; negative selects nowrap (raw DEFLATE).
- Return codes: -6 (Z_VERSION_ERROR), -2 (Z_STREAM_ERROR), -4 (Z_MEM_ERROR), 0 (Z_OK).
- `"1.1.4"` at `0x0064a260` — zlib version (only first char checked).
- Check function `0x0060be50` = adler32 (installed only when not nowrap).

## Corrected reconstruction
```c
int inflateInit2_(z_streamp z, int windowBits, const char *version, int stream_size)
{
    if (version == NULL || version[0] != ZLIB_VERSION[0] /*'1'*/ || stream_size != 0x48)
        return Z_VERSION_ERROR; // -6
    if (z == NULL)
        return Z_STREAM_ERROR;  // -2

    z->msg = NULL;
    if (z->zalloc == NULL) { z->zalloc = zcalloc; z->opaque = NULL; }
    if (z->zfree  == NULL) { z->zfree  = zcfree; }

    z->state = ZALLOC(z, 1, sizeof(internal_state) /*0x28*/);
    if (z->state == NULL)
        return Z_MEM_ERROR;     // -4

    z->state->blocks = NULL;    // +0x20
    z->state->nowrap = 0;       // +0x18
    if (windowBits < 0) { windowBits = -windowBits; z->state->nowrap = 1; }

    if (windowBits < 8 || windowBits > 15) {
        inflate_end(z);
        return Z_STREAM_ERROR;  // -2
    }
    z->state->wbits = windowBits; // +0x1c

    z->state->blocks = inflate_blocks_new(
        z, z->state->nowrap ? NULL : adler32 /*0x0060be50*/,
        (uInt)1 << windowBits);
    if (z->state->blocks == NULL) {
        inflate_end(z);
        return Z_MEM_ERROR;     // -4
    }

    inflate_reset(z);
    return Z_OK; // 0
}
```

## Evidence
- Raw decompile `FUN_0060acb0.c`: version-char + `param_4==0x48` gate → -6; default zalloc/zfree install
  (`thunk_FUN_0060c0f0`, `&LAB_0060bff0`); state ZALLOC 0x28; nowrap sign handling; 8..15 range check;
  `FUN_00608b70(z, nowrap?0:0x60be50, 1<<wbits)`; `FUN_0060abc0(z)` on success; `FUN_0060ac30(z)` on
  failure.
- Version string "1.1.4" at `0x0064a260`. Return codes match zlib error enum.

## Remaining uncertainty
- `0x0060be50` is identified as the adler32 check function by role (passed as checkfn, non-nowrap
  path); not separately reconstructed here. Confidence High from the exact zlib 1.1.4 correspondence;
  no runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060acb0.c`  — untouched decompiler output.
