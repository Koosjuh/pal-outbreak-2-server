# 0x0060f5e0 snap_socket_recv_blocking

| field | value |
|---|---|
| Original address | 0x0060f5e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f5e0 |
| Resolved name | snap_socket_recv_blocking |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060e160
**Callees:** func_0x0011a3c8 (syscall A), func_0x0011a5d0 (syscall B)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blocking transport primitive: retries syscall `0x11a3c8(handle, 0, 0, &out)` until it returns `>= 0` (non-negative), then, only on success, retries syscall `0x11a5d0(handle)` until it too returns `>= 0`. Both loops busy-spin on the negative (EWOULDBLOCK / retry) return, so the function does not return until both operations complete. `auStack_4` receives a 4-byte out value from the first call that is otherwise discarded here (the caller reads state elsewhere).

The two-syscall shape (a recv/peek that yields a length/status, then a commit/consume) is the classic "receive one message then advance the read cursor" pair on the SN@P socket.

## Input / output
- `param_1` (undefined8) — socket/connection handle.
- Return `void`.
- `auStack_4` — scratch 4-byte result of syscall A (local, discarded).

## Side effects
- Blocks the calling thread until both syscalls succeed (no timeout, no bound).
- Whatever kernel-side state syscall B advances (cursor/ack) is mutated.

## Important branches
| Condition | Consequence |
|---|---|
| `0x11a3c8(...) < 0` | retry (spin) |
| `0x11a3c8(...) >= 0` | proceed to second loop |
| `0x11a5d0(...) < 0` | retry (spin) |
| `0x11a5d0(...) >= 0` | return |

## Constants & flags
- No literals; `func_0x0011a3c8` / `func_0x0011a5d0` are fixed low-address syscall/library thunks (IOP/kernel net calls).

## Corrected reconstruction
```c
void snap_socket_recv_blocking(sock_handle h)
{
    long r;
    uint8_t out[4];                      // status/len from syscall A (discarded here)
    do { r = sys_net_a(h, 0, 0, out); } while (r < 0);   // 0x11a3c8: recv/peek
    if (r >= 0) {
        do { r = sys_net_b(h); } while (r < 0);          // 0x11a5d0: commit/advance
    }
    return;
}
```

## Evidence
- Two unconditional spin-until-nonneg loops; second gated on first's success.
- Callees are bare `func_0x001...` thunks (no corpus body) → kernel/library net syscalls.
- **Runtime-unvalidated**; exact syscall identities (recv vs poll) inferred from the two-step pattern.

## Remaining uncertainty
Identity of `0x11a3c8`/`0x11a5d0` (recv+consume vs open+accept) not confirmed; `out[4]` payload meaning unknown. Confidence Medium because the syscalls are opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f5e0.c`  — untouched decompiler output.
