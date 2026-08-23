# 0x0061ea40 empty_stub_ea40

| field | value |
|---|---|
| Original address | 0x0061ea40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061ea40 |
| Resolved name | empty_stub_ea40 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f970
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty no-op stub (single caller FUN_0061f970).

## Notes / uncertainty
No-op return; single-caller vacant hook slot.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061ea40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
