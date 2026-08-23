# 0x001ed21c pktbuf_tail_ptr

| field | value |
|---|---|
| Original address | 0x001ed21c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed21c |
| Resolved name | pktbuf_payload_tail |
| Subsystem | packets |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6988 (ack/advance), FUN_001ed270, FUN_001ed2c0, FUN_001ed74c, FUN_001ed864
**Callees:** FUN_001ebca8 (read used-length @+0x0c)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** pktbuf used-length @+0x0c
**State layout:** payload base = node+0x2c; write cursor = base + used_length.

## Behavioral explanation
Computes the append cursor (end of currently-used payload) for a packet buffer. Reads the used-length
u16 at node+0x0c via `FUN_001ebca8`, then returns `node + 0x2c + used_length` — the payload region
starts 0x2c bytes into the node and grows by `used_length`. Callers use the returned pointer as the
destination to append the next bytes/segment into the buffer.

## Input / output
- `param_1` (undefined8, used as int base): pktbuf node.
- Returns int: `node + 0x2c + used_length` — a raw pointer to the first free byte of payload.

## Side effects
- None (pure read + arithmetic).

## Important branches
- None (straight-line).

## Constants & flags
- `0x2c`: payload base offset within the node (header is bytes 0x00..0x2b). Consistent with
  `pktbuf_init_header` zeroing 0x10..0x28 and stamping length @+0x0c.

## Corrected reconstruction
```c
// Return the write cursor (end of used payload) of a pktbuf node.
u8 *pktbuf_payload_tail(pktbuf_node *n)
{
    u16 used = pktbuf_get_used_length(n);   // FUN_001ebca8: *(u16*)(n + 0x0c)
    return (u8*)n + 0x2c + used;
}
```

## Evidence
- Raw: `FUN_001ed21c.c`; callee `FUN_001ebca8.c` (returns `*(u16*)(param_1+0xc)`).
- Payload-base cross-check: `pktbuf_init_header` (`FUN_001ed034.c`) header region + used-length @+0xc.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether used-length counts payload bytes only (assumed) vs. header-inclusive is inferred from the +0x2c base.
