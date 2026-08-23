# 0x001ef310 snap_ipc_worker_init

| field | value |
|---|---|
| Original address | 0x001ef310 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef310 |
| Resolved name | snap_ipc_bind_rpc (snap_ipc_worker_init) |
| Subsystem | transport |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee110
**Callees:** CreateSema, FUN_00106b60 (memset), FUN_00115a98 (sceSifBindRpc-equivalent)
**Referenced globals:** 0x37aee0 (IPC mutex semaphore id); 0x37df10 (SifRpcClientData); 0x37df08 / 0x37df00 (queue counters); 0x37df34 (bound-server flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37df34 (client->server, nonzero once the RPC server is bound)

## Behavioral explanation
Bootstraps the EE→IOP IPC channel used by the SN@P RPC stubs (`FUN_001ef400` and the ~20 `snap_req_*`
callers). It lazily creates the IPC mutex semaphore (`0x37aee0`, initial + max count 1), zeroes the two
send/receive queue counters, then binds to the SN@P RPC server (id `0x1270110`) via `FUN_00115a98`
(sceSifBindRpc), busy-spinning `0x10000`-iteration delays and retrying until the bind call succeeds
(`>= 0`) **and** the client's bound-server field (`0x37df34`) becomes nonzero. Standard PS2 SIF RPC
bind-and-wait; it returns only when the transport can issue synchronous RPCs.

## Input / output
- **Params:** none.
- **Returns:** `0` (always; blocks until bound).

## Side effects
- Creates semaphore `0x37aee0` on first call (idempotent — guarded by `== 0`).
- Zeroes `0x37df08` and `0x37df00` (queue counters).
- Populates the `SifRpcClientData` at `0x37df10` (its `server` field `0x37df34` set by the bind).

## Important branches
- `iRam0037aee0 == 0` → create the semaphore (count 1/1); else reuse.
- Bind loop: while `FUN_00115a98(0x37df10, 0x1270110, 0) < 0` **or** `0x37df34 == 0` → busy-wait
  `0x10000` decrements, retry. Exits only when bind returns `>= 0` and the server handle is populated.

## Constants & flags
- `0x37aee0` = IPC serialisation semaphore (max/initial count 1 → binary mutex; taken/given by
  `FUN_001ef3e0`/`FUN_001ef3f0` around each RPC).
- `0x1270110` = the SN@P RPC server/registration id passed to bind.
- `0x10000` = spin-delay iteration count between bind retries.
- `0x37df34` = `SifRpcClientData.server` (bind-complete flag).

## Corrected reconstruction
```c
// Bind the EE side to the SN@P IOP RPC server; block until ready.
u64 snap_ipc_bind_rpc(void)
{
    if (g_ipc_sema /*0x37aee0*/ == 0) {
        struct sema_param sp;               // auStack_20 (0x18 bytes)
        memset(&sp, 0, 0x18);               // FUN_00106b60
        sp.init_count = 1;                  // uStack_1c
        sp.max_count  = 1;                  // uStack_18
        g_ipc_sema = CreateSema(&sp);
    }
    g_ipc_qcount_b /*0x37df08*/ = 0;
    g_ipc_qcount_a /*0x37df00*/ = 0;

    // sceSifBindRpc(&client@0x37df10, server_id=0x1270110, mode=0); retry until bound.
    while (sif_bind_rpc(&g_ipc_client /*0x37df10*/, 0x1270110, 0) < 0 ||
           g_ipc_client.server /*0x37df34*/ == 0) {
        for (int spin = 0x10000; spin != 0; spin--) { /* delay */ }
    }
    return 0;
}
```

## Evidence
- `CreateSema` with a 0x18-byte param and count 1/1 = a binary mutex; taken/released by the RPC wrapper
  `FUN_001ef4a0` via `FUN_001ef3e0`/`FUN_001ef3f0`.
- `FUN_00115a98(client, id, 0)` retried until `>= 0` and `client.server != 0` = the canonical
  sceSifBindRpc poll loop; `0x37df10` is the `SifRpcClientData` also used as the `cd` arg by `snap_ipc_send_msg`.
- Confidence **High** (textbook SIF RPC init); **Runtime validated: no**.

## Remaining uncertainty
Exact library-function identities (`FUN_00115a98`=sceSifBindRpc, `FUN_00115c68`=sceSifCallRpc) are
inferred from call shape, not symbol-confirmed. `0x1270110` as a server id vs a buffer address is inferred
from the bind-loop semantics.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef310.c`  — untouched decompiler output.
