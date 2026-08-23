# 0x0061e8f0 empty_stub_e8f0

| field | value |
|---|---|
| Original address | 0x0061e8f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e8f0 |
| Resolved name | empty_stub_e8f0 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_00622130, FUN_00622180
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty no-op stub (single caller FUN_00622180).

## Notes / uncertainty
Empty no-op (bare return); inferred disabled hook. Neighbor thunk_FUN_00619800 in same dump is a DIFFERENT address (keyboard flush) — not conflated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e8f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
