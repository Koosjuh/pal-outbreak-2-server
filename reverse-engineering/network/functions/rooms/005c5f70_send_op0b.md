# 0x005c5f70 send_op0b

| field | value |
|---|---|
| Original address | 0x005c5f70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5f70 |
| Resolved name | send_op0b_word |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bc240
**Callees:** — (memset `func_0x00106b60`; memcpy `func_0x001069a8`; send `func_0x001df380`)
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** app 0x0b
**State vars:** —

## Behavioral explanation
Emits a reliable **app-opcode 0x0b** control message carrying one 4-byte argument. Zero-fills a 0x304
stack body, sets `body[0]=0x0b`, copies 4 bytes from `param_2` into the body at offset +4, and sends
only **8 bytes** (opcode + 3 pad + 4-byte arg). This is the "one-word command" member of the
0x0b/0x0c/0x11 send family — same builder, different opcode. The word is almost certainly a room/slot
id or handle (caller `FUN_005bc240`).

## Input / output
- `param_1` (dest): destination endpoint / handle (send arg6).
- `param_2` (ptr→u32): source of the 4-byte argument copied to body+4.
- Returns void.

## Side effects
- One reliable app message, opcode 0x0b, length 8, channel 1, to `param_1`.

## Important branches
None.

## Constants & flags
- `0x0b` — app opcode. `0x8000` — SNAP_FLAG_RELIABLE. body length **8** (not 0x304). `1` — channel.
- Note: `memset` clears 0x304 but only 8 bytes are transmitted.

## Corrected reconstruction
```c
enum { OP_0B = 0x0b };
#define SNAP_FLAG_RELIABLE 0x8000

void send_op0b_word(void *dest /*param_1*/, const u32 *arg /*param_2*/)
{
    u8 body[0x310];
    memset(body, 0, 0x304);
    body[0] = OP_0B;                 // header byte at +0
    memcpy(&body[4], arg, 4);        // 4-byte argument at +4
    snap_send_app(g_net_ctx, SNAP_FLAG_RELIABLE, body, /*len*/8, /*channel*/1, dest);
}
```

## Evidence
- Raw: `auStack_310[0]=0xb`; `func_0x001069a8(auStack_30c,param_2,4)` (30c is body+4); send len 8.
- Twin builders differ only in `body[0]`: 0x0c=`send_op0c_prepare` (0x005c6050), 0x11=`send_op11` (0x005c60d0).
- op0b not in the supplied wire opcode list; role inferred from the 4-byte-id shape. Runtime-unvalidated.

## Remaining uncertainty
Exact meaning of the 4-byte word (room handle vs slot index vs sub-selector). Op0b semantics not yet
observed on the wire.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5f70.c`  — untouched decompiler output.
