# 0x001eedf0 snap_rpc_cmd01_failtest

| field | value |
|---|---|
| Original address | 0x001eedf0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eedf0 |
| Resolved name | snap_rpc_cmd01_failtest |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001ef540
**Referenced globals:** (via ef540) 0x37cf00 RPC send buf (0x37cf1c/0x37cf20/0x37cf24), 0x37bf00 RPC recv buf
**Referenced strings:** —
**Referenced opcodes:** SN@P IOP RPC cmd 0x01 (3-word request)
**State vars:** —

## Behavioral explanation
Predicate wrapper around RPC command **0x01** (`FUN_001ef540`, the 3-word variant). It loads two words
`a=param_1[0]`, `b=param_1[1]` from a caller struct, issues cmd 0x01 with args `(a, b, a | ~(a & b))`, and
returns a boolean mask: **`-1` (all-ones) when the RPC result is negative (failure), `0` otherwise**.
Called from the session state machine `FUN_001c19e0`.

**Key deep finding:** the third argument `a | ~(a & b)` algebraically reduces to a compile-time
**`~0` (0xFFFFFFFF)** — since `~(a&b) = ~a | ~b`, then `a | ~a | ~b = 0xFFFFFFFF` for any `a,b`. So cmd 0x01
is always invoked as `snap_rpc_cmd01(a, b, 0xFFFFFFFF)`; the all-ones third word is a constant "full mask /
match-any" parameter, not a computed value. The decompiler preserved the pre-simplified expression.

## Input / output
- `param_1` (`uint *`) — pointer to a 2-word request: `[0]=a`, `[1]=b`.
- **Returns** (int): `-1` if cmd 0x01 returned a negative result, else `0` (C `-(result<0)` boolean).

## Side effects
- Transitively (ef540): WaitSema(0x37aee0); send buf `0x37cf1c=a`, `0x37cf20=b`, `0x37cf24=0xFFFFFFFF`;
  `sceSifCallRpc` cmd 0x01 (send 0x2c / recv 0x20); reads `0x37bf18`; SignalSema.

## Important branches
- `sVar2 < 0` (RPC signalled failure) → return `-1`.
- else → return `0`.

## Constants & flags
- RPC cmd **0x01** — SN@P 3-word request (from ef540).
- Third arg **0xFFFFFFFF** — constant full mask (from the `a|~(a&b)` identity).
- Send framing **0x2c** send / **0x20** recv.

## Corrected reconstruction
```c
// bool snap_rpc_cmd01_fails(const u32 req[2])
int snap_rpc_cmd01_failtest(u32 *req) {
    u32 a = req[0], b = req[1];
    // third arg is a | ~(a & b)  ==  ~0  (0xFFFFFFFF) for all a,b
    short r = snap_rpc_cmd01(a, b, /*mask=*/0xFFFFFFFFu);  // FUN_001ef540, cmd 0x01
    return -(int)(r < 0);   // -1 on failure, 0 on success
}
```

## Evidence
- Raw: `uVar1 = *param_1; sVar2 = FUN_001ef540(uVar1, param_1[1], uVar1 | ~(uVar1 & param_1[1]));
  return -(uint)(sVar2 < 0);`.
- ef540: lock → `uRam0037cf1c=a; uRam0037cf20=b; uRam0037cf24=arg3` → `FUN_001ef400(1,0x37cf00,0x2c,
  0x37bf00,0x20)` → `0x37bf18` → unlock.
- Boolean identity `a|~(a&b) = a|~a|~b = ~0` (De Morgan).
- Prior record filename says "f0540"; the actual callee is **FUN_001ef540** (RPC cmd 0x01) — corrected.

## Remaining uncertainty
Semantic meaning of cmd 0x01 (what a/b select and what a negative result denotes — likely a
capability/availability probe) is not runtime-confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eedf0.c`  — untouched decompiler output.
