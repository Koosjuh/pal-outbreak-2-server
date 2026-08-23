# 0x001eee30 snap_state_enter_2_b

| field | value |
|---|---|
| Original address | 0x001eee30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eee30 |
| Resolved name | snap_state_enter_2_b |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001f06f0
**Referenced globals:** 0x37a288 (state var:=2)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288

## Behavioral explanation
Calls FUN_001f06f0() then sets state-machine var to 2.

## Notes / uncertainty
Bank-B state-2 entry: FUN_001f06f0() then state=2. Twin of 001eea10 without record pack. Bank A/B = caller context (001c0f40 vs 001c19e0).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eee30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
