# 0x001eefb0 snap_call_efe00_setflag_a2a5

| field | value |
|---|---|
| Original address | 0x001eefb0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eefb0 |
| Resolved name | snap_op1c_subscribe_setflag_a2a5 |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001efe00
**Referenced globals:** 0x37a2a5 (mode latch := 1 on success)
**Referenced strings:** —
**Referenced opcodes:** 0x1c (via FUN_001efe00)
**State vars:** 0x37a2a5

## Behavioral explanation
Set-half of the `a2a5` latch pair, and unlike the `a2a1/a2a2/a2a6` toggles this one's action is a **real SN@P RPC**: its callee `FUN_001efe00` is the op-0x1c RPC stub (locked `sceSifCallRpc` transaction, two u32 words, reqlen 0x28). So `FUN_001eefb0` = "issue op1c and, **only if it succeeded**, latch `a2a5 = 1`". On RPC failure (`< 0`) it forwards `-1` and leaves the latch untouched.

Because op1c is one of the transport room-list request opcodes and its twin op1d (`FUN_001efe70`, clears `a2a5` in `FUN_001ef000`) forms the OFF half, the `a2a5` latch most plausibly tracks an **enable/disable subscription** state — op1c = start (subscribe/enable), op1d = stop (unsubscribe/disable) — with the latch as the confirmed EE-side "subscription active" bit. This is the only latch in the bank gated on the call result, i.e. it records *confirmed* state, not intent.

## Input / output
- **Input:** none (void). (The op1c body words in `0x37cf1c/0x37cf20` are whatever the caller `0x001c19e0` last staged — this wrapper passes no args and lets `FUN_001efe00`'s default marshalling run.)
- **Output:** `short` — RPC result on success (`>= 0`), or `-1` on failure.

## Side effects
- On success only: `uRam0037a2a5 = 1`.
- Issues the op-0x1c RPC (via `FUN_001efe00` → `FUN_001ef400(0x1c,...)`), which serializes on the shared RPC semaphore and puts an op1c on the wire through the IOP net module.

## Important branches
- `FUN_001efe00() < 0` → return `-1`, **do not** set the latch (subscription not confirmed).
- else → set `a2a5 = 1`, return the RPC result.

## Constants & flags
- `0x37a2a5` — 1-byte "subscription/enable" latch; `1` = active (set here on success), `0` = inactive (cleared by `FUN_001ef000` after op1d).
- Opcode `0x1c` — SN@P room-list / subscription request (RPC cmd number).

## Corrected reconstruction
```c
// Issue op1c (subscribe/enable) and latch success.  [inferred: subscription semantics]
short snap_op1c_subscribe_setflag_a2a5(void)   // FUN_001eefb0
{
    short rc = snap_req_op1c();      // FUN_001efe00: locked sceSifCallRpc cmd 0x1c
    if (rc < 0)
        return -1;                  // failure: latch untouched
    g_subscribe_latch_a2a5 = 1;     // uRam0037a2a5: confirmed active
    return rc;
}
```

## Evidence
- Raw: `FUN_001eefb0.c` (15 lines).
- Callee `FUN_001efe00` = op1c RPC stub (this decompile set; reqlen 0x28, cmd 0x1c) — see `001efe00`.
- Twin `FUN_001ef000` clears the same latch after op1d — the matched pair pins the enable/disable reading.
- Runtime-unvalidated (subscription interpretation is inference from opcode pairing).

## Remaining uncertainty
Exact op1c/op1d payload semantics (what is being subscribed/enabled — room-list push? presence?) unconfirmed; the `a2a5` = "active" reading rests on the op1c/op1d enable/disable pairing plus the success-gated set.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eefb0.c`  — untouched decompiler output.
