# 0x005c3190 scenario_detail_request_sm

| field | value |
|---|---|
| Original address | 0x005c3190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3190 |
| Resolved name | scenario_detail_request_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf1e0, FUN_005c2b50, FUN_005c2f40
**Referenced globals:** 0x6cba50/54/55 (SM state/enable/reply flags); 0x6cba34 (completion callback ptr); 0x6cba44 (room index); 0x6fee68 (room record, stride 0x24); 0x6ff2b0 (create/own flag); 0x6cfa18/0x6cfb76 (room slot fields)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cba54; cRam006cba50; cRam006cba55; cRam006ff2b0

## Behavioral explanation
State machine (0x6cba50/54/55) that requests a room's scenario detail: from idle it either issues a transport request (0x1de0c0) against the room record at 0x6fee68 or, when 0x6ff2b0 is set, builds config locally (FUN_005c2f40) and copies the name; on completion invokes callback pcRam006cba34.

## Notes / uncertainty
Scenario-detail SM forks on host flag: joiner issues reliable op0a member-list (func_0x001de0c0) then builds live config on reply; host builds config locally and copies scenario name. 0x6cfa18 (live-arg) vs 0x6cfb76 (name) field roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
