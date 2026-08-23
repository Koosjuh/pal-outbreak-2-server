# 0x00631c80 softkbd_grid_up

| field | value |
|---|---|
| Original address | 0x00631c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631c80 |
| Resolved name | softkbd_grid_up |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00631910, FUN_00631a30, FUN_00633930
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x24/0x25 grid pos; +0x4a flags; +0x248 result code

## Behavioral explanation
Up key (0x52): moves grid cursor up (dir 2) when nav allowed, or steps IME candidate when in conversion state 1.

## Notes / uncertainty
Up: move grid row up (dir 2) or IME candidate step (+0x2f==1). Candidate-vs-segment ambiguity in FUN_00633930.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
