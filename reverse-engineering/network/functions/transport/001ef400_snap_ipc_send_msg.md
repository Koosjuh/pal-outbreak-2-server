# 0x001ef400 snap_ipc_send_msg

| field | value |
|---|---|
| Original address | 0x001ef400 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef400 |
| Resolved name | snap_ipc_call_rpc (snap_ipc_send_msg) |
| Subsystem | transport |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ef4a0 and the 20 `snap_req_*` / `snap_send_op*` RPC stubs (FUN_001ef4f0..FUN_001eff60)
**Callees:** FUN_00115c68 (sceSifCallRpc-equivalent)
**Referenced globals:** 0x37df10 (SifRpcClientData); 0x37cf00 (shared send buffer A); 0x37bf00 (shared receive buffer B)
**Referenced strings:** —
**Referenced opcodes:** — (transports every SN@P app opcode issued through the RPC path)
**State vars:** —

## Behavioral explanation
The core EE→IOP synchronous IPC transmit primitive behind every `snap_req_op*` stub. It rounds both the
send size (`param_3`) and receive size (`param_5`) **up to a 16-byte multiple** (EE↔IOP DMA alignment),
then issues a blocking RPC on the SN@P client (`0x37df10`) with function number `param_1`, using the
fixed shared DMA buffers `0x37cf00` (send) and `0x37bf00` (receive). The caller pre-fills `0x37cf00` with
the request and reads the reply out of `0x37bf00` after this returns.

## Input / output
- **param_1** (u64): RPC function number / message type (e.g. `5` from `snap_ipc_rpc_type5`).
- **param_2** (u64): the send buffer pointer (callers pass `0x37cf00`).
- **param_3** (uint): send size in bytes → 16-byte-aligned before the call.
- **param_4** (u64): the receive buffer pointer (callers pass `0x37bf00`).
- **param_5** (uint): receive size in bytes → 16-byte-aligned before the call.
- **Returns:** void. The reply lands in `0x37bf00`; callers read specific offsets (e.g. `0x37bf18`).

## Side effects
- Blocks on the SIF RPC until the IOP server replies (mode 0).
- Overwrites the shared receive buffer `0x37bf00`.

## Important branches
- Two identical 16-byte round-up computations for `param_5` and `param_3` (signed-safe: subtracts 0x10
  from the residue when the value is negative, then adds `0x10 - residue`). No other control flow; no
  error return (the underlying RPC call handles failure).

## Constants & flags
- `0x10` (16) = DMA alignment granularity for both transfer sizes.
- Call shape `FUN_00115c68(cd=0x37df10, fno=param_1, mode=0, send=0x37cf00, ssize, recv=0x37bf00, rsize,
  endfn=0, arg=0)` = `sceSifCallRpc(...)` in blocking mode.
- Buffers are process-global and fixed: `0x37cf00` (send A), `0x37bf00` (recv B).

## Corrected reconstruction
```c
// Blocking EE->IOP RPC. Aligns transfer sizes to 16 bytes (DMA requirement).
static inline u32 align16(u32 n) {
    u32 r = n & 0xf;
    if ((int)n < 0 && r != 0) r -= 0x10;        // signed residue fixup
    return r ? (0x10 - r) + n : n;
}

void snap_ipc_call_rpc(u32 fno, void *send, u32 ssize, void *recv, u32 rsize)
{
    rsize = align16(rsize);
    ssize = align16(ssize);
    sif_call_rpc(&g_ipc_client /*0x37df10*/, fno, /*mode*/0,
                 (void*)0x37cf00 /*send A*/,  ssize,
                 (void*)0x37bf00 /*recv B*/,  rsize,
                 /*endfunc*/0, /*endarg*/0);
    // Note: params `send`/`recv` are ignored — the fixed shared buffers are always used.
}
```

## Evidence
- 9-arg call to `FUN_00115c68` with client `0x37df10` (the object bound by `snap_ipc_worker_init`),
  mode 0, and the two fixed DMA buffers = `sceSifCallRpc` blocking form.
- 16-byte round-up on both sizes = the standard EE↔IOP DMA transfer-size constraint.
- 21 callers, all SN@P RPC stubs, confirm this is the shared transmit primitive.
- Confidence **High**; **Runtime validated: no** (library-function identity inferred from call shape).

## Remaining uncertainty
The passed `param_2`/`param_4` buffer pointers are overridden by the hardcoded `0x37cf00`/`0x37bf00` in
the call — so callers must stage into those globals regardless of what they pass. Whether `param_1` maps
1:1 to a SN@P app opcode or to an IOP-side handler index is set by the IOP server (not in this binary).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef400.c`  — untouched decompiler output.
