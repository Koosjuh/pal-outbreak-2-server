# 0x0062ff30 pad_input_init_edge_detect

| field | value |
|---|---|
| Original address | 0x0062ff30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ff30 |
| Resolved name | pad_input_init_edge_detect |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3f50, FUN_005f41e0
**Callees:** —
**Referenced globals:** iRam00715da8 (soft-kbd widget state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x37 init-once flag; +0x49c/0x49d/0x49e/0x49f/0x4a0/0x4a1 pad edge-detect bytes

## Behavioral explanation
One-shot init of pad-input edge-detect state: samples the controller (func 0x1d44f0) and latches button bits into the widget's +0x49c..0x4a1 edge fields.

## Notes / uncertainty
One-shot (+0x37 guard) softkbd pad edge-detect init; samples pad via 0x1d44f0, computes rising-edge btn mask +0x4a1 and new-key +0x49e. Pad-sample byte layout (pad[0]=btn,pad[2]=key) inferred; +0x37 reset site unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ff30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
