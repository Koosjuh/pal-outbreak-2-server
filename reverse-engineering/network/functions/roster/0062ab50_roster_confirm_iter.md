# 0x0062ab50 roster_confirm_iter

| field | value |
|---|---|
| Original address | 0x0062ab50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ab50 |
| Resolved name | roster_confirm_iter |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062a8c0
**Callees:** FUN_005b14b0, FUN_005b68e0, FUN_005b9060, FUN_005b9110, FUN_005c3e70
**Referenced globals:** +0x1460 slot idx; +0x5ec 0x300 text buf; 0x66ad50/0x66ad70 fmt str; 0x62b2c0 dialog cb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates the 3 roster slots (+0x1460 index over +0x1055) and opens a confirm dialog (FUN_005c3e70 callback 0x62b2c0) per occupied member; formats into +0x5ec.

## Notes / uncertainty
Per-slot confirm-dialog iterator over 3-entry array room+0x1055 (stride 0x25), screen 0x1d, cb 0x62b2c0. Table identity vs +0x12c2 member array (0x8a stride) unconfirmed; dialog helpers inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ab50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
