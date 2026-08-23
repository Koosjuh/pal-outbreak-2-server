# 0x001c3ea0 buf_write_be32

| field | value |
|---|---|
| Original address | 0x001c3ea0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3ea0 |
| Resolved name | buf_write_be32 (aka put_u32_be) |
| Subsystem | packets |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers (12):** FUN_001c4c80, FUN_001c51a0, FUN_001c5630, FUN_001c5900, FUN_001c5bd0, FUN_001c6060, FUN_001c64f0, FUN_001c6b90, FUN_001c6dc0, FUN_001c7580, FUN_001c8b60, FUN_001c94c0
**Callees:** FUN_001069a8 (memcpy)
**Referenced globals:** msgbuf obj+0x2c (tx base); obj+0x38 (tx length); obj+0x20 (capacity)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x38 tx length

## Behavioral explanation
Serialize a **big-endian** 32-bit value into the tx buffer with a bounds check — the widest write
primitive, and the exact counterpart of `buf_read_be32`. Byte-swaps the host word to big-endian,
computes the write position `tx_buf + tx_len`, and — only if `tx_len + 4 <= capacity` — copies 4
bytes and advances `tx_len` by 4; otherwise silently drops the write. Used by opcode builders for
32-bit fields (ids, seq, the 0xba476611 trailer, length words). Renamed `put_u32_be` → `buf_write_be32`
for symmetry with the read/write family.

## Input / output
- `param_1` (`msgbuf_t*`): message-buffer context.
- `param_2` (`u32`): host-order value to append big-endian.
- **return** (`int`/ptr): the pre-append write position `tx_buf + tx_len`.

## Side effects
- On fit: writes 4 big-endian bytes; `tx_len (+0x38) += 4`.
- On overflow: no write, `tx_len` unchanged.

## Important branches
- `tx_len + 4 <= capacity (+0x20)` → write + advance; else skip.

## Constants & flags
- Full 32-bit byte-swap `v<<24 | (v&0xff00)<<8 | v>>24 | (v>>8 & 0xff00)`.
- Object layout: `+0x2c` tx base, `+0x38` tx length, `+0x20` capacity.

## Corrected reconstruction
```c
int /*byte* pos*/ buf_write_be32(msgbuf_t *o /*param_1*/, u32 v /*param_2*/)
{
    u32 be = v << 24 | (v & 0xff00) << 8 | v >> 24 | (v >> 8 & 0xff00); // host -> BE
    u8 *pos = o->tx_buf + o->tx_len;
    if (o->tx_len + 4 <= o->capacity) {
        memcpy(pos, &be, 4);       // FUN_001069a8
        o->tx_len += 4;
    }
    return (int)pos;
}
```

## Evidence
- Raw decompile: swap `param_2<<0x18 | (param_2&0xff00)<<8 | param_2>>0x18 | param_2>>8 & 0xff00`;
  `iVar1=*(p+0x2c)+*(p+0x38)`; `if (*(p+0x38)+4U <= *(p+0x20)) { memcpy(iVar1,&be,4); *(p+0x38)+=4; }`.
- Exact write-side mirror of buf_read_be32; same tx triple/idiom as buf_write_u8 / buf_write_be16.
- Runtime-unvalidated.

## Remaining uncertainty
- None material (width-4 mirror of the write family).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3ea0.c`  — untouched decompiler output.
