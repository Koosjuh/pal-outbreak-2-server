# 0x001e5a00 sha1_transform_block

| field | value |
|---|---|
| Original address | 0x001e5a00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e5a00 |
| Resolved name | sha1_absorb_and_compress |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ea784 (sha1_update, flag=0), FUN_001ea804 (sha1_final, flag=1)
**Callees:** FUN_001069a8 (memcpy), FUN_001e5934 (byteswap the assembled block)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** SHA-1 ctx (see `sha1_init`)

## Behavioral explanation
The SHA-1 buffering + compression core. It appends bytes from the caller's cursor into the 64-byte block
buffer; whenever a full 64-byte block is assembled (or a finalize is requested), it endian-normalizes the
block (`FUN_001e5934`), expands the 80-word schedule, runs the four 20-step rounds with the SHA-1
constants, and folds the result into H0..H4. On finalize it appends the `0x80` padding byte, zero-fills,
and — if there is room (buffer index < 0x39) — writes the 64-bit bit-length into the last two words so the
message-length block is consumed in the same pass; otherwise it compresses the padding block now and
returns "true" so `sha1_final` calls again for the length-only block.

The 80 rounds are fully inlined/unrolled in the decompile (constants `0x5a827999`, `0x6ed9eba1`,
`0x8f1bbcdc`, `0xca62c1d6`; the final H0 add uses `-0x359d3e2a` = `0xca62c1d6`). W[16..79] are expanded
in place with the SHA-1 recurrence `W[i] = rotl1(W[i-3]^W[i-8]^W[i-14]^W[i-16])`.

## Input / output
- `param_1` (uint*) — SHA-1 ctx.
- `param_2` (int*) — in/out pointer to the input **cursor** (advanced by bytes consumed).
- `param_3` (uint*) — in/out pointer to the **remaining byte count** (decremented to 0 on partial fill).
- `param_4` (int) — finalize flag (0 = absorb only, 1 = finalize/pad).
- Returns `bool` — `true` when a further finalize pass is needed (padding overflowed a block; the length
  still has to be emitted), i.e. `buffer_index_before_pad > 0x38`.

## Side effects
- `memcpy` into ctx block buffer (`ctx+0x24+count`).
- Advances `*param_2`, decrements `*param_3`, updates `ctx->buf_count` (+0x1c).
- Updates the 64-bit bit length (`ctx[5]/[6]`) with carry.
- On finalize: sets pad flag (+0x20), writes length words at `ctx[0x17]/[0x18]`, byteswaps the block, runs
  compression, and folds H0..H4.

## Important branches
- **`*param_3 < 0x40 - buf_count`** (input does not fill the block):
  - copy the partial input in (if len ≠ 0), advance cursor, `*param_3 = 0`.
  - if `param_4 == 0` → **return true** (absorb-only, wait for more) — no compression.
  - else (finalize): snapshot `count`, reset `buf_count = 0`, add `count*8` bits with carry, append `0x80`
    if not already, zero-fill to 0x40; if `count < 0x39` write length at [0x17]/[0x18] and byteswap first
    0x38 bytes (data words only — length words left big-endian), else byteswap the whole 0x40 (length goes
    to the next block). Fall through to compression.
- **else** (input fills the block): copy `0x40 - buf_count` bytes, advance cursor/remaining, `buf_count=0`,
  add 512 (`0x200`) bits with carry, byteswap the whole block. Fall through to compression.
- **Return `0x38 < snapshot_count`**: only meaningful on the finalize/overflow path — signals `sha1_final`
  to run one more (length-only) block.

## Constants & flags
- Round constants `0x5a827999` (ch, r0-19), `0x6ed9eba1` (parity, r20-39), `0x8f1bbcdc` (maj, r40-59),
  `0xca62c1d6` (parity, r60-79; appears as `-0x359d3e2a` in the final H0 add).
- Block size `0x40` (64 B / 512 bits); schedule `0x50` (80) words at `ctx+0x24` (word 9).
- Pad byte `0x80`; length-fit threshold `0x39` (56 bytes ⇒ 8 bytes left for the length).

## Corrected reconstruction
```c
/* Absorb up to one block from the cursor and, on a full block or finalize,
   run one SHA-1 compression. Returns true if finalize needs another pass. */
bool sha1_absorb_and_compress(sha1_ctx *c, const uint8_t **cursor,
                              int *remaining, int finalize)
{
    uint32_t saved = 0;

    if ((uint32_t)*remaining < 0x40 - c->buf_count) {
        /* partial: buffer what we have */
        if (*remaining) {
            memcpy((uint8_t*)c->w + c->buf_count, *cursor, *remaining);
            *cursor    += *remaining;
            c->buf_count += *remaining;
            *remaining  = 0;
        }
        if (!finalize) return true;               /* absorb-only: wait */

        /* --- finalize this (last) block --- */
        saved = c->buf_count;
        c->buf_count = 0;
        uint32_t bits = c->len_lo + saved * 8;    /* add message bits, carry */
        if (bits < saved * 8) c->len_hi++;
        c->len_lo = bits;

        if (!c->pad_flag) {                        /* append 0x80 once */
            ((uint8_t*)c->w)[saved++] = 0x80;
            c->pad_flag = 1;
        }
        for (uint32_t i = saved; i < 0x40; i++)    /* zero-fill */
            ((uint8_t*)c->w)[i] = 0;

        if ((int)saved < 0x39) {                   /* length fits this block */
            c->w[0x17 - 9] = c->len_hi;            /* words [0x17],[0x18] */
            c->w[0x18 - 9] = c->len_lo;
            byteswap_u32_array(c->w, 0x38);        /* swap data words only  */
        } else {
            byteswap_u32_array(c->w, 0x40);        /* length spills to next */
        }
    } else {
        /* full block: top off the buffer, count 512 bits */
        memcpy((uint8_t*)c->w + c->buf_count, *cursor, 0x40 - c->buf_count);
        *cursor    += 0x40 - c->buf_count;
        *remaining -= 0x40 - c->buf_count;
        c->buf_count = 0;
        uint32_t bits = c->len_lo + 0x200;
        if (bits < 0x200) c->len_hi++;
        c->len_lo = bits;
        byteswap_u32_array(c->w, 0x40);
    }

    /* ---- SHA-1 compression (80 steps, unrolled in the binary) ---- */
    uint32_t a=c->h[0], b=c->h[1], cc=c->h[2], d=c->h[3], e=c->h[4];
    for (int i = 16; i < 80; i++)                  /* W schedule expansion */
        c->w[i] = rotl32(c->w[i-3]^c->w[i-8]^c->w[i-14]^c->w[i-16], 1);
    for (int i = 0; i < 80; i++) {
        uint32_t f, k;
        if      (i < 20) { f = (b & cc) | (~b & d);            k = 0x5a827999; }
        else if (i < 40) { f = b ^ cc ^ d;                    k = 0x6ed9eba1; }
        else if (i < 60) { f = (b & cc) | (b & d) | (cc & d); k = 0x8f1bbcdc; }
        else             { f = b ^ cc ^ d;                    k = 0xca62c1d6; }
        uint32_t t = rotl32(a,5) + f + e + c->w[i] + k;
        e = d; d = cc; cc = rotl32(b,30); b = a; a = t;
    }
    c->h[0]+=a; c->h[1]+=b; c->h[2]+=cc; c->h[3]+=d; c->h[4]+=e;

    return (int)saved > 0x38;                       /* need a length-only pass? */
}
```

## Evidence
- Round constants `0x5a827999/0x6ed9eba1/0x8f1bbcdc/0xca62c1d6`, the `rotl1` W-expansion
  (`W[i-3]^W[i-8]^W[i-14]^W[i-16]`) written to `param_1[0x19..0x58]`, and the H-fold at the tail are
  unmistakable SHA-1. Buffer at `+0x24` and length words at `[0x17]/[0x18]` match `sha1_init`. Callers
  `FUN_001ea784` (flag 0) and `FUN_001ea804` (flag 1) confirm absorb vs finalize. Runtime-unvalidated
  (identified by the constants + structure).
- The reconstructed 80-step loop is the canonical equivalent of the unrolled decompile; the exact
  per-step operations in the raw `.c` are preserved verbatim there.

## Remaining uncertainty
- The decompile mixes `a/b/c/d/e` register roles across the unrolled steps; the canonical loop above is
  behaviorally equivalent but the raw text is the ground truth if a byte-exact reimplementation is needed.
- `f`-selection for rounds 0-19 in the raw appears as `((c^d)&b)^d` (= `(b&c)|(~b&d)`), matching standard
  "ch"; confirmed algebraically, not by trace.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e5a00.c`  — untouched decompiler output.
