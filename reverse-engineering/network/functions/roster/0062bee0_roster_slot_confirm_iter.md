# 0x0062bee0 roster_slot_confirm_iter

| field | value |
|---|---|
| Original address | 0x0062bee0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062bee0 |
| Resolved name | roster_slot_confirm_iter |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062bda0
**Callees:** FUN_005b68e0, FUN_005b9110, FUN_005c3ef0
**Referenced globals:** +0x1460 slot idx; +0x10b4 dialog result; +0x42b state; 0x62cc60 dialog cb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates occupied roster slots (+0x1460 over +0x1055) opening a confirm dialog (FUN_005c3ef0 cb 0x62cc60); stores per-slot result (0xff/1) and sets +0x42b=0x1e; when done advances.

## Notes / uncertainty
Two-phase sibling of 0062ab50; records per-slot verdict into SM block +0x10+i (0xFF accept / 1 deny), screen 0x1e, cb 0x62cc60. Verdict/outcome-step downstream meaning unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062bee0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
