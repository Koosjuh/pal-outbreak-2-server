# 0x005ef850 ui_node_stack_push_alloc

| field | value |
|---|---|
| Original address | 0x005ef850 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef850 |
| Resolved name | ui_node_stack_push_alloc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ea820, FUN_005ea880, FUN_005eb0f0, FUN_005eb1d0, FUN_005eb5a0, FUN_005eb640, FUN_005eb6f0, FUN_005eb750, FUN_005f0930, FUN_005f0a10, FUN_005f0b20, FUN_005f0e10, FUN_005f10a0
**Callees:** —
**Referenced globals:** +0xd890 global node counter (<499); +0xd892 stack depth (<0x10); +0xd894 current node idx; +0xd89a stack array; +0xd8ba max-depth watermark; +0x24e0 node pool; node+0x10/+0xc link ptrs
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd890; +0xd892; +0xd894; +0xd8ba

## Behavioral explanation
Core layout-node allocator: bumps global node index (cap 499) and stack depth (cap 0x10), links the new 0x5c-byte node into the pool at +0x24e0, returns 0/-1.

## Notes / uncertainty
Core UI layout-node allocator: bump global count +0xd890 (cap 499) + depth +0xd892 (cap 0x10), 0x5c-byte node in pool +0x24e0, in-use +0x4e; link pass (+0x186==0xf6/-10) does parent DLL child-splice via +0xd898[depth]. NOT the SN@P sub-pool. Dual stack arrays +0xd898/+0xd89a and full +0x186 pass-mode set inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef850.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
