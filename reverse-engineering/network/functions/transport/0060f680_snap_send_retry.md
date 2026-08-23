# 0x0060f680 snap_socket_send_retry

| field | value |
|---|---|
| Original address | 0x0060f680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f680 |
| Resolved name | snap_socket_send_retry |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060e060
**Callees:** func_0x0011a9f8 (send, 3-arg), func_0x0011aa18 (sendto, 4-arg)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bounded/unbounded retry wrapper around one of two send syscalls. It selects the variant by whether an address argument (`param_4`) is supplied, and retries on the negative (would-block) return either forever (`param_5 == 0`) or up to `param_5` attempts.

- `param_4 == 0` → connected send `0x11a9f8(handle, buf, len)`.
- `param_4 != 0` → addressed send `0x11aa18(handle, buf, len, addr)`.
- `param_5 == 0` → spin until the call returns `>= 0`.
- `param_5 > 0` → try at most `param_5` times, stopping early on success.

The result of the syscall is discarded (`void` return); the caller relies on the retry contract (best-effort with a cap) rather than an explicit status.

## Input / output
- `param_1` (undefined8) — socket handle.
- `param_2` (undefined8) — buffer pointer.
- `param_3` (undefined8) — length.
- `param_4` (long) — destination address (0 = connected socket).
- `param_5` (int) — max attempts (0 = unbounded).
- Return `void`.

## Side effects
- Transmits `param_3` bytes from `param_2` on the socket; may transmit 0 times if all attempts would-block and `param_5` is exhausted.

## Important branches
| Condition | Consequence |
|---|---|
| `param_4 == 0` & `param_5 == 0` | spin `0x11a9f8` until ≥0 |
| `param_4 == 0` & `param_5 > 0` | try `0x11a9f8` ≤ param_5 times |
| `param_4 != 0` & `param_5 == 0` | spin `0x11aa18` (with addr) until ≥0 |
| `param_4 != 0` & `param_5 > 0` | try `0x11aa18` ≤ param_5 times |

## Constants & flags
- No literals; `0x11a9f8` = `send`-class thunk, `0x11aa18` = `sendto`-class thunk (extra addr arg). Identity inferred from the 3-arg vs 4-arg split.

## Corrected reconstruction
```c
void snap_socket_send_retry(sock_handle h, const void *buf, size_t len,
                            const sockaddr *dst /*param_4*/, int max_tries /*param_5*/)
{
    long r; int tries = 0;
    if (dst == NULL) {
        if (max_tries == 0) { do { r = sys_send(h, buf, len); } while (r < 0); }
        else { bool go = 0 < max_tries;
               while (go && (r = sys_send(h, buf, len)) < 0) go = (++tries < max_tries); }
    } else {
        if (max_tries == 0) { do { r = sys_sendto(h, buf, len, dst); } while (r < 0); }
        else { bool go = 0 < max_tries;
               while (go && (r = sys_sendto(h, buf, len, dst)) < 0) go = (++tries < max_tries); }
    }
}
```

## Evidence
- 2×2 branch matrix on `param_4` (addr present) and `param_5` (bounded) with the exact same retry body.
- Callees are opaque low-address net thunks; the 4th arg only on the `param_4!=0` path → sendto semantics.
- **Runtime-unvalidated**.

## Remaining uncertainty
Whether `0x11a9f8`/`0x11aa18` are `send`/`sendto` or a device ioctl pair is unproven; return value is dropped so callers can't distinguish "sent" from "gave up". Confidence Medium (opaque syscalls).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f680.c`  — untouched decompiler output.
