# 0x001ef000 snap_call_efe70_clrflag_a2a5

| field | value |
|---|---|
| Original address | 0x001ef000 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef000 |
| Resolved name | snap_op1d_unsubscribe_clrflag_a2a5 |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001efe70
**Referenced globals:** 0x37a2a5 (mode latch := 0 on success)
**Referenced strings:** —
**Referenced opcodes:** 0x1d (via FUN_001efe70)
**State vars:** 0x37a2a5

## Behavioral explanation
Clear-half of the `a2a5` latch pair — the OFF twin of `FUN_001eefb0`. Its action is the op-0x1d RPC stub `FUN_001efe70` (locked `sceSifCallRpc`, cmd 0x1d, two u32 words, reqlen 0x28), the counterpart to op1c. It issues op1d and, **only on success**, clears `uRam0037a2a5 = 0` (subscription/enable now inactive); on failure it returns `-1` and leaves the latch set.

op1c/op1d being an adjacent enable/disable pair (both twin RPCs, same reqlen 0x28, sharing the `a2a5` latch, set-on-op1c / clear-on-op1d) is the strongest evidence that this latch is a confirmed "subscription active" bit rather than a bare intent flag.

## Input / output
- **Input:** none (void).
- **Output:** `short` — RPC result on success (`>= 0`), or `-1` on failure.

## Side effects
- On success only: `uRam0037a2a5 = 0`.
- Issues the op-0x1d RPC through the IOP net module (serialized on the shared RPC semaphore).

## Important branches
- `FUN_001efe70() < 0` → return `-1`, **do not** clear the latch (still considered active).
- else → clear `a2a5 = 0`, return the RPC result.

## Constants & flags
- `0x37a2a5` — 1-byte subscription/enable latch; cleared to `0` here on success.
- Opcode `0x1d` — SN@P op1c twin (unsubscribe/disable), RPC cmd number.

## Corrected reconstruction
```c
// Issue op1d (unsubscribe/disable) and clear the latch on success.
short snap_op1d_unsubscribe_clrflag_a2a5(void)   // FUN_001ef000
{
    short rc = snap_req_op1d();      // FUN_001efe70: locked sceSifCallRpc cmd 0x1d
    if (rc < 0)
        return -1;                  // failure: latch stays set
    g_subscribe_latch_a2a5 = 0;     // uRam0037a2a5: confirmed inactive
    return rc;
}
```

## Evidence
- Raw: `FUN_001ef000.c` (15 lines).
- Callee `FUN_001efe70` = op1d RPC stub (this set; cmd 0x1d, reqlen 0x28) — see `001efe70`. Twin of `FUN_001efe00`/op1c.
- Set-half `FUN_001eefb0` sets the same latch after op1c.
- Runtime-unvalidated.

## Remaining uncertainty
Same as the op1c set-half: the subscribed/enabled resource is not pinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef000.c`  — untouched decompiler output.
