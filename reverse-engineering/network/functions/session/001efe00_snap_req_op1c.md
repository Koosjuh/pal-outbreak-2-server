# 0x001efe00 snap_req_op1c

| field | value |
|---|---|
| Original address | 0x001efe00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efe00 |
| Resolved name | snap_req_op1c_roomlist |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eefb0
**Callees:** FUN_001ef3e0 (lock), FUN_001ef3f0 (unlock), FUN_001ef400 (txn)
**Referenced globals:** 0x37cf1c (req word0, 4B); 0x37cf20 (req word1, 4B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x1c
**State vars:** —

## Behavioral explanation
Synchronous SN@P RPC stub for transport op **0x1c**, a two-32-bit-word command returning only a result word.
Same semaphore-guarded scratch path (see 0x001ef690): `WaitSema` → word0 at req+0x1c, word1 at req+0x20 →
`snap_rpc_txn(0x1c, 0x37cf00, 0x28, 0x37bf00, 0x20)` → result at resp+0x18 → `SignalSema`. Request length 0x28
= 0x1c header + 2 words (8 bytes) + padding.

0x1c is in the transport **room-list** op band (0x1c/0x1e/0x20 list). op1c is the list-request/control side;
its twin op1d (0x001efe70) has an identical body with opcode 0x1d. The two 32-bit words are most plausibly a
(cursor/page, filter/count) or (start-index, page-size) pair that parameterizes the room-list query.
Semantics inferred; body shape certain.

## Input / output
- `param_1` (u32, req+0x1c): word0 (list cursor / start [inferred]).
- `param_2` (u32, req+0x20): word1 (count / filter [inferred]).
- Returns `u16` result code (resp+0x18).

## Side effects
- Semaphore 0x37aee0; shared scratch overwrite; one reliable op-0x1c packet on session 0x37df10, blocks for reply.

## Important branches
- None; straight-line stub.

## Constants & flags
- `0x1c` transport room-list op band (0x1c/0x1e/0x20). `0x28` reqlen / `0x20` resplen.

## Corrected reconstruction
```c
// op 0x1c = room-list request/control, two 32-bit params [inferred meanings]
u16 snap_req_op1c_roomlist(u32 word0 /*cursor?*/, u32 word1 /*count?*/)
{
    snap_rpc_lock();                              // WaitSema(0x37aee0)
    *(u32 *)(SNAP_REQ_BUF + 0x1c) = word0;        // 0x37cf1c
    *(u32 *)(SNAP_REQ_BUF + 0x20) = word1;        // 0x37cf20
    snap_rpc_txn(0x1c, (void*)SNAP_REQ_BUF, 0x28, (void*)SNAP_RESP_BUF, 0x20);
    u16 result = *(u16 *)(SNAP_RESP_BUF + 0x18);  // 0x37bf18
    snap_rpc_unlock();                            // SignalSema(0x37aee0)
    return result;
}
```

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efe00.c`  — untouched decompiler output.

## Evidence
- Raw: writes 0x37cf1c/0x37cf20; `FUN_001ef400(0x1c,0x37cf00,0x28,0x37bf00,0x20)`; returns 0x37bf18.
- Opcode 0x1c = transport room-list band per task/PACKET_INDEX. Helper contract shared with op08 family. Structure Confirmed; params Inferred.

## Remaining uncertainty
- Exact meaning of the two words and the op1c/op1d division of labor. Runtime-unvalidated.
