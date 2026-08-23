# 0x005f5fe0 playerlist_rebuild

| field | value |
|---|---|
| Original address | 0x005f5fe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5fe0 |
| Resolved name | playerlist_rebuild |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f5f80
**Callees:** FUN_005f61d0, FUN_005f62e0
**Referenced globals:** 0x695d8c/88(registry recency/flag); 0x70a150(display list, 0x12c0 bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x695d8c

## Behavioral explanation
Rebuilds the visible player-list rows by scanning the 100-entry name registry (active + recently-active entries) into a display array.

## Notes / uncertainty
Two-pass rebuild of player list from registry: active (+0x2c!=0) then known-offline (+0x2c==0 && +0x28!=0). FUN_005f61d0 append reads implicit iterator (not decoded).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5fe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
