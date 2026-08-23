# 0x0061ea20 empty_stub_ea20

| field | value |
|---|---|
| Original address | 0x0061ea20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061ea20 |
| Resolved name | empty_stub_ea20 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f9f0, FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00620d60, FUN_00622c30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty no-op stub (6 menu callers) — hook placeholder.

## Notes / uncertainty
No-op return; vacant hook slot (6 callers), same bank as ea10/ea40/f1a0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061ea20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
