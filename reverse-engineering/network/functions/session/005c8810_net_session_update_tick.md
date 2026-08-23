# 0x005c8810 net_session_update_tick

| field | value |
|---|---|
| Original address | 0x005c8810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8810 |
| Resolved name | net_session_update_tick |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae310, FUN_006076c0, FUN_00608300, FUN_006088b0, FUN_00624c70
**Callees:** FUN_005c85d0, FUN_005d80c0, FUN_005deb00, FUN_005e0390
**Referenced globals:** 0x642bd0 (mode driver fn-table); 0x701f20 (host/join mode); 0x700fe0 (result code)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701f20; 0x700fe0

## Behavioral explanation
Main per-frame network-session update: runs sub-updates, the connect handler, then dispatches the mode-specific driver via table PTR_FUN_00642bd0[0x701f20]; returns result code 0x700fe0.

## Notes / uncertainty
Top of the per-frame session loop: transport pump, txn_pump, connect handler, then mode driver PTR_FUN_00642bd0[host/join], returns 0x700fe0. Roles of FUN_005deb00/005e0390 inferred from position.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
