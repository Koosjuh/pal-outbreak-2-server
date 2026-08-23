# 0x005f7270 wait_overlay_sm

| field | value |
|---|---|
| Original address | 0x005f7270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7270 |
| Resolved name | wait_overlay_sm |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6b00, FUN_005f6d20
**Callees:** FUN_005be690, FUN_005be700, FUN_005f70b0, FUN_005f7440
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x429 (overlay step); param+0x16 (timer); param+0x42b (fade level 0x20)

## Behavioral explanation
State machine on +0x429 (0-5) for the animated 'connecting/please wait' overlay: fade-in timers (FUN_005be690/700 start cb 0x5f7490), draws via FUN_005f70b0, checks confirm input FUN_005f7440; returns done flag to the parent connect SM.

## Notes / uncertainty
6-state fade-in/hold/fade-out/dismiss SM on +0x429; context code (param2&0xff) selects style and confirm-gate. Codes {1,3} wait for confirm, others auto-dismiss. Exact context-code semantics inferred from branch partitions.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
