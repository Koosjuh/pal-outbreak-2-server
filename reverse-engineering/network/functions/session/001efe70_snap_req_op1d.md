# 0x001efe70 snap_req_op1d

| field | value |
|---|---|
| Original address | 0x001efe70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efe70 |
| Resolved name | snap_req_op1d_roomlist |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef000
**Callees:** FUN_001ef3e0 (lock), FUN_001ef3f0 (unlock), FUN_001ef400 (txn)
**Referenced globals:** 0x37cf1c (req word0, 4B); 0x37cf20 (req word1, 4B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x1d
**State vars:** —

## Behavioral explanation
Synchronous SN@P RPC stub for transport op **0x1d**, byte-for-byte identical to op1c (0x001efe00) except the
opcode: two 32-bit words in, result word out, over the shared semaphore-guarded scratch (see 0x001ef690).
`WaitSema` → word0 at req+0x1c, word1 at req+0x20 → `snap_rpc_txn(0x1d, 0x37cf00, 0x28, 0x37bf00, 0x20)` →
result at resp+0x18 → `SignalSema`.

op1c/op1d are a paired transport room-list family (0x1c/0x1e/0x20 list band). Distinct callers (op1c from
FUN_001eefb0, op1d from FUN_001ef000) suggest a request/continue or open/next split of the same listing
protocol. The two words likely mirror op1c's (cursor, count) parameters. Semantics inferred; body certain.

## Input / output
- `param_1` (u32, req+0x1c): word0 (list cursor / continuation [inferred]).
- `param_2` (u32, req+0x20): word1 (count / filter [inferred]).
- Returns `u16` result code (resp+0x18).

## Side effects
- Semaphore 0x37aee0; shared scratch overwrite; one reliable op-0x1d packet on session 0x37df10, blocks for reply.

## Important branches
- None; straight-line stub.

## Constants & flags
- `0x1d` transport room-list op (op1c twin). `0x28` reqlen / `0x20` resplen.

## Corrected reconstruction
```c
// op 0x1d = room-list request/continue, two 32-bit params (op1c twin) [inferred meanings]
u16 snap_req_op1d_roomlist(u32 word0 /*cursor?*/, u32 word1 /*count?*/)
{
    snap_rpc_lock();                              // WaitSema(0x37aee0)
    *(u32 *)(SNAP_REQ_BUF + 0x1c) = word0;        // 0x37cf1c
    *(u32 *)(SNAP_REQ_BUF + 0x20) = word1;        // 0x37cf20
    snap_rpc_txn(0x1d, (void*)SNAP_REQ_BUF, 0x28, (void*)SNAP_RESP_BUF, 0x20);
    u16 result = *(u16 *)(SNAP_RESP_BUF + 0x18);  // 0x37bf18
    snap_rpc_unlock();                            // SignalSema(0x37aee0)
    return result;
}
```

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efe70.c`  — untouched decompiler output.

## Evidence
- Raw: writes 0x37cf1c/0x37cf20; `FUN_001ef400(0x1d,0x37cf00,0x28,0x37bf00,0x20)`; returns 0x37bf18.
- Identical body to op1c stub, opcode +1; both in transport room-list band. Helper contract shared with op08 family. Structure Confirmed.

## Remaining uncertainty
- The op1c-vs-op1d role split and the meaning of the two words. Runtime-unvalidated.
