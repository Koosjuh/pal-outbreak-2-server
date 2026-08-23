# 0x00606cb0 dispatch_by_conn_mode

| field | value |
|---|---|
| Original address | 0x00606cb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606cb0 |
| Resolved name | dispatch_by_conn_mode |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_005f4550, FUN_006082e0
**Referenced globals:** 0x003c8a80 conn-mode flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam003c8a80

## Behavioral explanation
Branches to FUN_005f4550 or FUN_006082e0 depending on connection-mode flag 3c8a80.

## Notes / uncertainty
Per-frame router on conn-mode flag 0x3c8a80: 0->FUN_005f4550 (local), else FUN_006082e0 (online room-query). flag==0 exact sub-mode not deep-read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606cb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
