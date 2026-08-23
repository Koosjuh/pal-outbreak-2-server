# 0x005d78d0 session_node_lookup_or_insert

| field | value |
|---|---|
| Original address | 0x005d78d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d78d0 |
| Resolved name | session_node_lookup_or_insert |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7f80
**Callees:** FUN_005d6a70, FUN_005d6b40, FUN_005d6c10, FUN_005d6ce0
**Referenced globals:** 0x004f47c roster pool head; 0x00701000 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00701000; node+0x104 state; node+0x108 who-byte

## Behavioral explanation
Finds a roster node (pool 0x4f47c) by key; if absent allocates one (evicting oldest) and marks state 3; if present-and-state5 either releases it (when mode cRam00701000==5 and who-byte mismatches param_3) or reactivates it to state 2.

## Notes / uncertainty
Renamed from roster_lookup_or_insert: session-node pool (0x4f47c) lookup-or-insert commit gate. No active node -> reserve (evict oldest if full) and set state 3; active node usable only if state 5, then reactivate to state 2, or release on mode-5 (cRam00701000==5) who-byte(+0x108) mismatch, else reject 0. Pool-helper semantics (6a70 find vs 6c10 reserve) inferred; param_2 unused here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d78d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
