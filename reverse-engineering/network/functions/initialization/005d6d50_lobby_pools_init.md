# 0x005d6d50 lobby_pools_init

| field | value |
|---|---|
| Original address | 0x005d6d50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6d50 |
| Resolved name | lobby_pools_init |
| Subsystem | initialization |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c80a0
**Callees:** FUN_005d7690, FUN_005dee40
**Referenced globals:** 0x00701040 session pool base; 0x00701038 roster pool base; 0x00701030 roomlist pool base; 0x00701028 txn pool base; 0x00701020 buf-index table; 0x004f370/0x4f47c/0x4f588/0x4f694 pool heads; 0x00701018 current-room ptr; 0x00700ff8 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701018; uRam00700ff8

## Behavioral explanation
Constructs the four lobby object pools (session 0x114/2, roster 0x11c/31, room-list 0x10c/31, txn-queue 0x128/19), links each free-list, wires session data buffers, then calls sub-init and zeroes the state block at 0x701000.

## Notes / uncertainty
Already fully reconstructed. Builds 4 free-list pools (session x3/roster x32/roomlist x32/txn x20) in session arena; node counts corrected from memset sizes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6d50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
