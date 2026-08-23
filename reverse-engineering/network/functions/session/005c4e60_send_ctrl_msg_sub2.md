# 0x005c4e60 send_ctrl_msg_sub2

| field | value |
|---|---|
| Original address | 0x005c4e60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4e60 |
| Resolved name | send_named_ctrl_msg_sub2 |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005be330
**Callees:** func_0x00106b60 (memset), func_0x0010a050 (strlen), func_0x001069a8 (strcpy), func_0x001de840 (net send)
**Referenced globals:** 0x36842c (user name string buffer); 0x6febac (SN@P net/connection handle)
**Referenced strings:** str@0x36842c
**Referenced opcodes:** app control message, sub-selector = 2
**State vars:** —

## Behavioral explanation
Sub-selector-**2** twin of `send_named_ctrl_msg_sub1` (0x5c4dc0). Identical build-and-send of the
named control message carrying the local user name `0x36842c`, differing only in `byte[1] = 2`. Reached
from `FUN_005be330` (a create/enter path) whereas sub1 comes from `FUN_005bfb40`; the two callers +
two selectors implement the two phases/variants of the same named handshake.

Frame layout: `[0]=0, [1]=2, [2]=0, [3]=strlen(name), [4..5]=0, [6..]=name`; sent length =
`strlen(name)+6`, who-byte `0x1000` (DATA), on conn `0x6febac`.

## Input / output
- **Params:** none.
- **Return:** void.

## Side effects
- Sends one DATA datagram on `0x6febac`: `send(conn, buf, strlen(name)+6, who=0x1000)`.

## Important branches
- None — straight-line; length data-dependent.

## Constants & flags
- `sub-selector = 2` (vs 1 in 0x5c4dc0). `who = 0x1000` (DATA). memset span `0x56`. Same thunks
  (memset/strlen/strcpy/send) as the twin.

## Corrected reconstruction
```c
void send_named_ctrl_msg_sub2(void)
{
    u8 buf[0x56];
    memset(buf, 0, 0x56);
    buf[0] = 0;
    buf[1] = 2;                    // sub-selector (variant 2)
    buf[2] = 0;
    u8 nlen = (u8)strlen((char*)0x36842c);
    buf[3] = nlen;
    strcpy((char*)&buf[6], (char*)0x36842c);
    snap_send(g_conn /*0x6febac*/, buf, nlen + 6, /*who=*/0x1000);
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005c4e60.c` (size 152). Only `uStack_5f=2` differs
  from 0x5c4dc0.

## Remaining uncertainty
- Same as the twin: unmapped to a numbered app opcode; the sub1/sub2 pairing (request vs confirm, or
  two message classes) inferred from the two call sites; runtime-unvalidated.
