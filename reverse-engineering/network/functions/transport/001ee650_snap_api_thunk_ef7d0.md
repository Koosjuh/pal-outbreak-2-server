# 0x001ee650 snap_release_ef7d0

| field | value |
|---|---|
| Original address | 0x001ee650 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee650 |
| Resolved name | snap_release_ef7d0 |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9780, FUN_001ca3a0, FUN_001ca590
**Callees:** FUN_001ee150, FUN_001ef7d0
**Referenced globals:** (via ef7d0) 0x37cf00 RPC send buf, 0x37bf00 RPC recv buf
**Referenced strings:** —
**Referenced opcodes:** SN@P IOP RPC cmd 0x0c (release/close-B)
**State vars:** —

## Behavioral explanation
Fire-and-forget release: forwards a single u16 id to RPC command **0x0c** (`FUN_001ef7d0`), pushes the
result through the identity post-processor, and discards it (`void`). Unlike ee5f0/ee680 it takes the id
*by value* and does not invalidate any slot — the caller owns lifecycle. Used by the room/list teardown
callers 0x1c9780 / 0x1ca3a0 / 0x1ca590.

## Input / output
- `param_1` (u16) — SN@P id to release (handle-class-B, distinct from cmd 0x0b/0x4a classes).
- **Returns** void.

## Side effects
- Transitively (ef7d0): WaitSema(0x37aee0), send buf `0x37cf1c`=id, `sceSifCallRpc` cmd 0x0c (send 0x22 /
  recv 0x20), SignalSema. Result read into `0x37bf18` but dropped by this wrapper.

## Important branches
None — straight-line lock/call/unlock inside ef7d0; wrapper has no conditionals.

## Constants & flags
- RPC cmd **0x0c** — SN@P release/close handle-class-B (from ef7d0).
- Send framing **0x22** send / **0x20** recv.

## Corrected reconstruction
```c
// void snap_release(u16 id)   // handle-class-B, RPC 0x0c
void snap_release_ef7d0(u16 id) {
    u16 r = snap_rpc_close_0c(id);   // FUN_001ef7d0, cmd 0x0c
    (void)identity(r);               // FUN_001ee150 (no-op); result discarded
}
```

## Evidence
- Raw: `uVar1 = FUN_001ef7d0(param_1); FUN_001ee150(uVar1); return;`.
- ef7d0: lock → `uRam0037cf1c = param_1` → `FUN_001ef400(0xc,0x37cf00,0x22,0x37bf00,0x20)` → `0x37bf18` →
  unlock.
- Sibling of ee5f0 (0x0b) / ee680 (0x4a): same RPC frame, different command id.

## Remaining uncertainty
Which SN@P object cmd 0x0c releases (vs 0x0b/0x4a) is unconfirmed at runtime; grouped by caller context
(room-list teardown) only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee650.c`  — untouched decompiler output.
