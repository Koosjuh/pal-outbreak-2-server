# 0x00615670 net_request_prepare

| field | value |
|---|---|
| Original address | 0x00615670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615670 |
| Resolved name | net_request_prepare |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e060, FUN_006156b0, FUN_00615778, FUN_006158c8, FUN_00615930, FUN_006159c0, FUN_00615e20, FUN_00615ea8, FUN_00615f48, FUN_00615fc8, FUN_00616048, FUN_006160a0, FUN_006160f8, FUN_00616150, FUN_006161d8, FUN_00616210, FUN_00616250, FUN_00616288
**Callees:** FUN_006155c8 (net_resolver_open)
**Referenced globals:** 0x70d240 (request buffer, 0x310 bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70d240

## Behavioral explanation
Shared prologue for the entire `0x70d200` async-request family (18 callers). It (1) ensures the resolver channel is open via `net_resolver_open`, then (2) zeroes the `0x310`-byte request/parameter buffer at `0x70d240`, giving every issue_tN / start / abort a clean slate before it writes its type-specific fields. The return value is the `net_resolver_open` result (propagated so a failed open aborts the request), though most callers ignore it.

`0x310` matches the buffer copied out by `net_request_result_copy` (0x70d240..0x70d540 + 16-byte tail) — the same block is used for both the outbound request and the inbound result.

## Input / output
- No parameters.
- Return `undefined8` — pass-through of `net_resolver_open()` (0 = ready, 0xffffffff = open failed).

## Side effects
- May open the resolver channel (first call).
- `memset(0x70d240, 0, 0x310)` — clears the request buffer.

## Important branches
None (straight-line: open-check then memset). Branching lives in the callee `net_resolver_open`.

## Constants & flags
- `0x310` (784) — request/parameter buffer size at `0x70d240`.
- `0x70d240` — request buffer base (= result buffer base).

## Corrected reconstruction
```c
undefined8 net_request_prepare(void)
{
    undefined8 rc = net_resolver_open();           // 6155c8: lazy-open channel
    memset((void*)0x70d240, 0, 0x310);             // clear request/param buffer
    return rc;                                      // most callers ignore
}
```

## Evidence
- 18 callers across the request family all use it as the first step before writing fields → confirmed shared prologue.
- Buffer size `0x310` reconciles with `net_request_result_copy` (0x70d240→0x70d540 = 0x300, + 0x10 tail).
- Straight-line; **runtime-unvalidated** but high confidence (trivial).

## Remaining uncertainty
None material; only the ultimate purpose of the channel (see net_resolver_open) is open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615670.c`  — untouched decompiler output.
