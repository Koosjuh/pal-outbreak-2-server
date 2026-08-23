# 0x00628110 query_op11_send_step

| field | value |
|---|---|
| Original address | 0x00628110 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628110 |
| Resolved name | query_op11_send_step |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60
**Callees:** FUN_005b14b0, FUN_005b7fd0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x11
**State vars:** —

## Behavioral explanation
Sub-step of the member machine that emits app opcode 0x11 (room/member query) via FUN_005b7fd0 and waits on the reliable-send window before setting the +0x443 done flag.

## Notes / uncertainty
Accurate 3-substate op11 send/drain machine; case-1 logic (0x10==0 && 0x200!=0 -> done, else retry) matches raw. FUN_005b14b0 channel polarity inferred; record[8] payload source undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
