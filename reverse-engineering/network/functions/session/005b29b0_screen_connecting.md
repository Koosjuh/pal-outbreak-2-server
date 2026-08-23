# 0x005b29b0 screen_connecting

| field | value |
|---|---|
| Original address | 0x005b29b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b29b0 |
| Resolved name | screen_connecting |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005b14b0
**Referenced globals:** 0x638c70/0x638c90/0x638cb0 status string ptrs
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0xe screen id

## Behavioral explanation
Screen-1 'connecting/please-wait' state: 4 sub-states that draw three status strings and wait for a button/timer before advancing.

## Notes / uncertainty
4-step wait-screen SM on ctx+0xf; step1 allocs input widget(mask0x10)+draws 3 status strings(0x638c70/90/cb0), step3 hands to screen id 2. String texts and screen-2 identity not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b29b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
