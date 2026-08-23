# 0x005c85d0 connect_establish_state_handler

| field | value |
|---|---|
| Original address | 0x005c85d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c85d0 |
| Resolved name | connect_establish_state_handler |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8810
**Callees:** FUN_005c8530, FUN_005d5ba0, FUN_005d5c20, FUN_005d8930
**Referenced globals:** 0x701e10 (submenu state); 0x701f20 (host/join mode); 0x700ff0; 0x701068+0x68f90 (established flag); 0x642bc8 (compared peer string); 0x701070+1 (session state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+1 (state); 0x701f20 (host/join)

## Behavioral explanation
Connection-establish handler: on link status (func_0x001ee360 => 1/2/3) latches connected, compares peer id string (0x642bc8), and branches host vs join (0x701f20) to advance the session state (0x701070+1).

## Notes / uncertainty
Establish gate (ticked by 0x5c8810): latches arena+0x68f90 on link status 1/2/3, verifies peer string 0x642bc8, then forks host(0x701f20==1)/join by kind 0x701070+0x2e. Meaning of 0x642bc8 string and join args 0xd/0xe inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c85d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
