# 0x005c4dc0 send_ctrl_msg_sub1

| field | value |
|---|---|
| Original address | 0x005c4dc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4dc0 |
| Resolved name | send_named_ctrl_msg_sub1 |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bfb40
**Callees:** func_0x00106b60 (memset), func_0x0010a050 (strlen), func_0x001069a8 (strcpy), func_0x001de840 (net send)
**Referenced globals:** 0x36842c (user name string buffer); 0x6febac (SN@P net/connection handle)
**Referenced strings:** str@0x36842c
**Referenced opcodes:** app control message, sub-selector = 1
**State vars:** —

## Behavioral explanation
Builds and sends a short app-layer control message that carries the local user's name string
(`0x36842c`) with sub-selector byte **1**. It zero-fills an 0x56-byte stack frame, writes a small
fixed header, appends the strlen and the name bytes, then hands the buffer to the SN@P send routine
`func_0x001de840` on the current connection `0x6febac` with who-byte `0x1000` (DATA). The twin
`send_ctrl_msg_sub2` (0x5c4e60) is identical except the sub-selector byte is 2 — so byte[1] selects
one of two control variants (e.g. request vs. confirm of the same named operation).

Frame layout (offsets within the 0x56-byte buffer, header zeroed then patched):
- byte[0] = 0                      (message type / opcode field)
- byte[1] = 1                      (sub-selector — the variant, =2 in the twin)
- byte[2] = 0
- byte[3] = strlen(name)           (payload length)
- byte[4..5] = 0                   (remain zero from the memset)
- byte[6..] = name string (copied from 0x36842c)
- total bytes sent = strlen(name) + 6

## Input / output
- **Params:** none (reads globals).
- **Return:** void.

## Side effects
- Sends one DATA datagram on connection `0x6febac`: `send(conn, buf, strlen(name)+6, who=0x1000)`.
- No global state written (stack-local build only).

## Important branches
- None — straight-line build-and-send. Length is data-dependent (`strlen(0x36842c) + 6`).

## Constants & flags
- `who = 0x1000` — DATA who-byte (per SN@P transport facts; 0x1000=DATA / 0x2000 other).
- `sub-selector = 1` (this fn) vs `= 2` (0x5c4e60).
- `0x56` — memset span of the build buffer.
- `func_0x00106b60`=memset, `func_0x0010a050`=strlen, `func_0x001069a8`=strcpy,
  `func_0x001de840`=SN@P send.

## Corrected reconstruction
```c
// name string @ 0x36842c ; conn handle @ 0x6febac
void send_named_ctrl_msg_sub1(void)
{
    u8 buf[0x56];
    memset(buf, 0, 0x56);          // func_0x00106b60

    buf[0] = 0;                    // type
    buf[1] = 1;                    // sub-selector (variant 1)
    buf[2] = 0;
    u8 nlen = (u8)strlen((char*)0x36842c);  // func_0x0010a050
    buf[3] = nlen;                 // payload length
    strcpy((char*)&buf[6], (char*)0x36842c); // func_0x001069a8 (name at offset 6)

    snap_send(g_conn /*0x6febac*/, buf, nlen + 6, /*who=*/0x1000); // func_0x001de840
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005c4dc0.c` (size 152). `uStack_5f=1`,
  `bStack_5d=strlen(0x36842c)`, `func_0x001de840(uRam006febac,&buf,strlen+6,0x1000)`.
- Stack layout: `bStack_5d` at −0x5d, `auStack_5a` at −0x5a → name payload begins at buffer offset 6.
- 0x36842c = name buffer (GLOBALS: `0x36842c name-buf`); 0x6febac = connection handle (GLOBALS/MEMORY).

## Remaining uncertainty
- The exact protocol opcode this maps to (byte[0]=0, sub=1) is not tied to a named app opcode from the
  index; it is a distinct short control message, not one of the numbered room ops.
- Whether the reliable bit is OR'd inside `func_0x001de840` (who=0x1000 passed here has no 0x8000).
- Runtime-unvalidated.
