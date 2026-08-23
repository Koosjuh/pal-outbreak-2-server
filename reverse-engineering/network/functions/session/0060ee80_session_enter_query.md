# 0x0060ee80 session_enter_query

| field | value |
|---|---|
| Original address | 0x0060ee80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060ee80 |
| Resolved name | session_enter_query |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_006157e0, FUN_006157e8, FUN_00616150
**Referenced globals:** ctx+0x19af4/0x19ae0 (conn); ctx+0x19b34 (reply buf); ctx+0x197c0 (status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x197c0 status

## Behavioral explanation
Issues one transport query (FUN_00616150 into +0x19b34), spins the poll, reads status into +0x197c0 and returns true iff status == -0x14.

## Notes / uncertainty
Blocking submit/pump/status query; true iff status==-0x14(-20). Human meaning of -20 vs the -0xf sibling code needs wire/PINE trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060ee80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
