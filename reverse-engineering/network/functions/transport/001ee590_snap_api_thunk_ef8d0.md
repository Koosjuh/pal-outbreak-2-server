# 0x001ee590 snap_send_retlen_ef8d0

| field | value |
|---|---|
| Original address | 0x001ee590 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee590 |
| Resolved name | snap_send_retlen_ef8d0 |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4070, FUN_001c4100, FUN_001c42d0, FUN_001c43c0, FUN_001c4560, FUN_001c46a0, FUN_001c48c0, FUN_001c4c80, FUN_001c4fb0, FUN_001c51a0, FUN_001c5480, FUN_001c5630, FUN_001c5900, FUN_001c5bd0, FUN_001c5ea0, FUN_001c6060, FUN_001c6330, FUN_001c64f0, FUN_001c67b0, FUN_001c69b0, FUN_001c6b90, FUN_001c6dc0, FUN_001c7000, FUN_001c7580, FUN_001c7980, FUN_001c85c0, FUN_001c8b60, FUN_001c8d30, FUN_001c8dd0, FUN_001c8f50, FUN_001c94c0
**Callees:** FUN_001ee150, FUN_001ef8d0
**Referenced globals:** (via ef8d0) 0x37cf00 RPC send buf, 0x37bf00 RPC recv buf
**Referenced strings:** —
**Referenced opcodes:** SN@P IOP RPC cmd 0x0f (send-data)
**State vars:** —

## Behavioral explanation
Public "send SN@P message" wrapper. Tail-forwards the caller's `(handle, payload_ptr, len)` to the IOP
RPC stub `FUN_001ef8d0` (SIF-RPC command **0x0f** = send data), post-processes through the identity
helper `FUN_001ee150`, then normalizes the return: **on RPC success (result==0) it returns the requested
length `param_3` (bytes-accepted convention); on failure it returns the RPC result verbatim** (a negative
error). This is the classic "return N on success, else errno" send idiom used pervasively by the
0x1c4xxx–0x1c9xxx builders that emit reliable app packets.

The decompiler only shows `FUN_001ef8d0(param_1)` because a1/a2 (`payload`, `len`) pass straight through
in registers to a callee with the same first-three-arg ABI — a tail-forward, not a 1-arg call.

## Input / output
- `param_1` (u16) — SN@P connection/handle id.
- `param_2` (ptr, u64 in ABI) — payload buffer (copied IOP-side by ef8d0 via FUN_001069a8).
- `param_3` (short) — payload length in bytes.
- **Returns** (short): `param_3` on success; the RPC result (`0x37bf18`, negative errno) on failure.

## Side effects
None locally. Transitively (through ef8d0): takes the SN@P RPC semaphore 0x37aee0, writes the shared send
buffer 0x37cf00 (`+0x1c`=handle, `+0x1e`=len, `+0x20..`=payload), issues `sceSifCallRpc` cmd 0x0f, reads
result from recv buffer 0x37bf00 (`+0x18`).

## Important branches
- `(-1 < sVar2) && (sVar2 == 0)` → RPC returned exactly 0 (success) → substitute `param_3` as the return.
- Any other `sVar2` (negative errno, or the len-was-<1 zero path inside ef8d0) → returned unchanged.
- Edge: ef8d0 clamps `len` to 0xc00 (3072) IOP-side, but this wrapper still returns the *original*
  `param_3` on success — an over-length caller sees a byte count larger than what was actually sent.
- Edge: `param_3 < 1` → ef8d0 returns 0 without doing the RPC → this wrapper returns `param_3` (≤0).

## Constants & flags
- RPC cmd **0x0f** — SN@P send-data (from ef8d0).
- **0xc00** — IOP-side max payload clamp (from ef8d0).
- **0x26** — fixed header prepended to `len` for the send-buffer size (`param_3 + 0x26`, from ef8d0).

## Corrected reconstruction
```c
// short snap_send(u16 handle, const void *payload, short len)
short snap_send_retlen_ef8d0(u16 handle, const void *payload, short len /*a2*/) {
    short r = snap_rpc_send_data_0f(handle, payload, len);  // FUN_001ef8d0, cmd 0x0f
    r = (short)identity(r);                                 // FUN_001ee150 (no-op)
    if (r >= 0 && r == 0)      // i.e. RPC succeeded
        return len;            // report requested length as bytes-sent
    return r;                  // negative errno on failure
}
```

## Evidence
- Raw: `FUN_001ef8d0(param_1)` then `FUN_001ee150`; `if ((-1 < sVar2) && (sVar2 == 0)) sVar2 = param_3;`.
- ef8d0 body: `FUN_001ef3e0()`(lock) → fill `0037cf1c/1e`, `FUN_001069a8(0x37cf20,payload,len)` →
  `FUN_001ef400(0xf,0x37cf00,len+0x26,0x37bf00,len+0x26)` → `uRam0037bf18` → `FUN_001ef3f0()`(unlock);
  `if (param_3 < 1) return 0; if (0xc00 < param_3) param_3 = 0xc00;`.
- ef400 → `FUN_00115c68(0x37df10,cmd,0,0x37cf00,..,0x37bf00,..,0)` (sceSifCallRpc on the SN@P RPC channel).
- FUN_001ee150 = `return param_1;` (identity).

## Remaining uncertainty
The a1/a2 tail-forward is inferred from ABI + ef8d0's signature (not visible in this frame). The
"bytes-accepted" meaning of the substituted length is by-convention, runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee590.c`  — untouched decompiler output.
