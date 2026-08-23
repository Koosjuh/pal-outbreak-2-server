# 0x005c61b0 send_op0f

| field | value |
|---|---|
| Original address | 0x005c61b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c61b0 |
| Resolved name | send_op0f_bare |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (no direct callers in the binary per the raw decompile; table-dispatched or dead)
**Callees:** — (memset `func_0x00106b60`; send `func_0x001df380`)
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** app 0x0f
**State vars:** —

## Behavioral explanation
Emits a reliable **app-opcode 0x0f** bare control message with no payload. Byte-identical to
`send_op0e_bare` except `body[0]=0x0f`: zero-fill 0x304, opcode at +0, transmit 4 bytes. A pure-signal
message. The raw decompile records **zero direct callers**, so it is either reached through a dispatch
table (function pointer) or unused in this build; the op0e twin (0x005c6150) is reachable, suggesting
op0f is the paired counterpart of a signal pair (e.g. enable/disable, ready/unready).

## Input / output
- `param_1` (dest): destination (send arg6).
- Returns void.

## Side effects
- One reliable app message, opcode 0x0f, length 4, channel 1, to `param_1`.

## Important branches
None.

## Constants & flags
- `0x0f` — app opcode. `0x8000` — SNAP_FLAG_RELIABLE. length **4**. `1` — channel.

## Corrected reconstruction
```c
enum { OP_0F = 0x0f };
#define SNAP_FLAG_RELIABLE 0x8000

void send_op0f_bare(void *dest /*param_1*/)
{
    u8 body[0x310];
    memset(body, 0, 0x304);
    body[0] = OP_0F;
    snap_send_app(g_net_ctx, SNAP_FLAG_RELIABLE, body, /*len*/4, /*channel*/1, dest);
}
```

## Evidence
- Raw: `auStack_310[0]=0xf`; `func_0x001df380(uRam006febac,0x8000,body,4,1,param_1)`; `CALLERS (0)`.
- Twin of `send_op0e_bare`. op0f not in the supplied wire list. Runtime-unvalidated.

## Remaining uncertainty
Whether op0f is live in this build (no static caller) and its precise pairing with op0e.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c61b0.c`  — untouched decompiler output.
