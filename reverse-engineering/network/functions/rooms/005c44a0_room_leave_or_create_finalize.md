# 0x005c44a0 room_leave_or_create_finalize

| field | value |
|---|---|
| Original address | 0x005c44a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c44a0 |
| Resolved name | room_leave_or_create_finalize |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fed10, FUN_005ff690, FUN_0062e440
**Callees:** FUN_005bdfe0, FUN_005bf1e0, FUN_005bf230, FUN_005c5ff0
**Referenced globals:** 0x6ff2b0 (create/own flag); 0x6cfb70 (slot 'active/committed' field, stride 0x144); 0x6d2158 (current slot); 0x6cbc84/7e (state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2b0; uRam006cbc84; uRam006cbc7e

## Behavioral explanation
Handles room teardown/finalize: mode0 just clears 0x6cbc84 and defers to bf230; when the create flag 0x6ff2b0 is set it marks the slot record (idx*0x144+0x6cfb70 = 1), sets current slot, enters UI state 0x10 and kicks bdfe0(0x21); otherwise routes to FUN_005c5ff0.

## Notes / uncertainty
Three-way finalize: mode0 dismiss; joiner (0x6ff2b0==0) stores ctx + sends op02 to 0x6febe8; host marks slot committed 0x6cfb70=1, sets roster-panel 0x6cbc7e=0x10, redraw 0x21. The 0x6cfb70 write is directly on the 'host room shows only CREATOR' render path. op02 leave-vs-ack reading inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c44a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
