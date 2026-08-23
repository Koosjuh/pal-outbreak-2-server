# 0x001ef2e0 snap_rpc_channel_idle

| field | value |
|---|---|
| Original address | 0x001ef2e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef2e0 |
| Resolved name | snap_rpc_channel_idle |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee160
**Callees:** FUN_00115e60
**Referenced globals:** 0x37df10 (SN@P SIF-RPC client-data / channel handle)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Readiness predicate for the SN@P IOP RPC channel. Calls `FUN_00115e60(0x37df10)` — a SIF-RPC status probe
(sceSifCheckStatRpc-shaped) on the same client-data handle `0x37df10` that `FUN_001ef400` marshals every
SN@P command through — and returns **true iff it reports 0 (idle / not-busy)**. Used by `FUN_001ee160`
before dispatching, to gate access to the single shared RPC channel (the buffers 0x37cf00/0x37bf00 must
not be reused while a call is in flight).

`0x37df10` is the RPC client-data struct, not a message queue; the prior name "msgq_is_empty" is
functionally close (nothing pending) but the object is the RPC channel — renamed `snap_rpc_channel_idle`.

## Input / output
- No parameters.
- **Returns** (bool): `true` when `FUN_00115e60(0x37df10) == 0` (channel idle), else `false` (busy).

## Side effects
None — pure read of the SIF-RPC channel status.

## Important branches
- `lVar1 == 0` → return true (idle).
- `lVar1 != 0` → return false (a call is pending / channel bound-busy).

## Constants & flags
- **0x37df10** — SN@P SIF-RPC client-data handle (shared with ef400/ef2e0).

## Corrected reconstruction
```c
// bool snap_rpc_channel_idle(void)
bool snap_rpc_channel_idle(void) {
    return sif_rpc_stat(&g_snap_rpc_client /*0x37df10*/) == 0;   // FUN_00115e60
}
```

## Evidence
- Raw: `lVar1 = FUN_00115e60(0x37df10); return lVar1 == 0;`.
- `0x37df10` is the exact handle passed as arg0 of `FUN_00115c68` inside FUN_001ef400 (the RPC dispatcher),
  confirming it is the RPC channel, not a queue.

## Remaining uncertainty
`FUN_00115e60`'s exact libc/SIF identity (CheckStatRpc vs BindRpc-status) is inferred from the handle and
usage; `0`-means-idle polarity is unvalidated at runtime.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef2e0.c`  — untouched decompiler output.
