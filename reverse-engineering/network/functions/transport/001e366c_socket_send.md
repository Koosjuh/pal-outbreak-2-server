# 0x001e366c socket_send

| field | value |
|---|---|
| Original address | 0x001e366c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e366c |
| Resolved name | socket_send_or_recv |
| Subsystem | transport |
| Relevance | core |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00103de8 (errno slot), FUN_001e2a28 (fd → slot), FUN_001e4bec (stream pump), FUN_001efb80 (stream transmit), FUN_001eb434 (dgram dequeue), FUN_001ed7e0 (copy payload out), FUN_001ec9e0 (free)
**Referenced globals:** PTR_0025b798 socket table; DAT_0025b79c device/pool handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** slot+2 type (1=stream / 2=dgram); slot+4 state (0x7f/0xff4 connected, -1 closed)

## Behavioral explanation
A dual-mode socket I/O entry that dispatches by socket type. For a **stream** socket (type 1) in a connected state (`0x7f` or `0xff4`), it pumps the stream engine (`FUN_001e4bec`) and transmits the buffer via `FUN_001efb80`. For a **datagram** socket (type 2), it dequeues one buffered packet (`FUN_001eb434`) and reads its payload out through `FUN_001ed7e0`, freeing the packet to the device pool (`DAT_0025b79c`) — i.e. the datagram branch performs a receive-one. The `-0x1b56` "queue empty" sentinel is normalized to `0` (zero bytes). Errors set errno and return `-1`.

## Input / output
- **param_1** (`undefined4` fd): socket descriptor.
- **param_2** (`undefined4` buf): buffer (source for stream send, destination for dgram read).
- **param_3** (`undefined4` len): length.
- **Return** (`short`): stream/dgram byte result, `0` on empty dgram queue, `-1` on error.

## Side effects
- Stream: pumps `FUN_001e4bec` and sends via `FUN_001efb80`.
- Datagram: dequeues + frees one packet from the device pool `DAT_0025b79c`.
- Sets the thread errno slot on failure.

## Important branches
- `FUN_001e2a28(fd) == NULL` → errno `0x6c`; return -1.
- `slot[2] == -1` (closed) → errno `0xe`; return -1.
- `slot[1] == 1` (stream): `FUN_001e4bec(slot) == 0 && (state==0x7f || state==0xff4)` → `FUN_001efb80(slot[0], buf, (u16)len)`.
- `slot[1] == 2` (dgram): `FUN_001eb434(...)`:
  - `-0x1b56` (empty) → return 0.
  - `0` → `FUN_001ed7e0(node, buf, len)`; free node.
  - else → errno = err; return -1.
- other type → errno `0x6b`; return -1.

## Constants & flags
- slot layout: `[0]` native fd, `[1]` type (`1`=stream, `2`=dgram), `[2]` state (`0x7f`/`0xff4` connected, `-1` closed).
- errno: `0x6c` (bad fd), `0xe` (closed/fault), `0x6b` (wrong type).
- `-0x1b56` — queue-empty sentinel → normalized to 0.

## Corrected reconstruction
```c
// Dual-mode: stream socket transmits; datagram socket receives one queued packet.
enum { SOCK_STREAM=1, SOCK_DGRAM=2 };
enum { ST_CONN=0x7f, ST_CONN2=0xff4, ST_CLOSED=-1 };
enum { E_BADFD=0x6c, E_FAULT=0x0e, E_BADTYPE=0x6b, PKT_EMPTY=-0x1b56 };

short socket_send_or_recv(u32 fd /*param_1*/, void *buf /*param_2*/, u32 len /*param_3*/)
{
    *errno_slot() = 0;
    u16 *slot = (u16*)FUN_001e2a28(fd);
    if (slot == NULL)          { *errno_slot() = E_BADFD; return -1; }
    if ((s16)slot[2] == ST_CLOSED) { *errno_slot() = E_FAULT; return -1; }

    short r;
    if (slot[1] == SOCK_STREAM) {
        r = (short)FUN_001e4bec(slot);                      // pump stream
        if (r == 0 && (slot[2] == ST_CONN || slot[2] == ST_CONN2))
            r = FUN_001efb80(slot[0], buf, (u16)len);       // stream transmit
    } else if (slot[1] == SOCK_DGRAM) {
        void *node; u32 tmp;
        short s = FUN_001eb434(slot + 4 /*queue*/, &node);
        if (s == PKT_EMPTY)      r = 0;                     // empty → 0 bytes
        else if (s == 0) { r = FUN_001ed7e0(node, buf, len);   // read one datagram
                           FUN_001ec9e0(DAT_0025b79c, node); } // free to device pool
        else             { *errno_slot() = s; r = -1; }
    } else { *errno_slot() = E_BADTYPE; r = -1; }
    return r;
}
```

## Evidence
- Type dispatch on `slot[1]` (1 stream / 2 dgram) and connected-state gate `0x7f`/`0xff4` mirror `socket_sendto`/`socket_recvfrom` slot conventions.
- Datagram branch dequeues via `FUN_001eb434` and frees to `DAT_0025b79c` (the device/pool handle documented in GLOBALS `0x25b79c net device handle`).
- `-0x1b56 → 0` normalization is the shared empty-queue idiom.
- Runtime-unvalidated.

## Remaining uncertainty
- **Naming:** the datagram branch reads (receives) while the stream branch sends, so this is a shared I/O entry rather than a pure `send`. Whether `FUN_001efb80` is send or recv on the stream side is not independently confirmed; renamed to `socket_send_or_recv` to avoid over-committing. No callers are recorded in this corpus, so its role in the app path is unverified.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e366c.c`  — untouched decompiler output.
