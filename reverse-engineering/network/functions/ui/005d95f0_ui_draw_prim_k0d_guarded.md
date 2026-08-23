# 0x005d95f0 ui_draw_prim_k0d_guarded

| field | value |
|---|---|
| Original address | 0x005d95f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d95f0 |
| Resolved name | ui_draw_prim_k0d_guarded |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ef3f0
**Callees:** FUN_005cab10, FUN_005da730
**Referenced globals:** iRam00701068+0x68e7e: UI widget/state flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e7e

## Behavioral explanation
UI overlay primitive: if drag-mode inactive, sets UI flag 0x68e7e to 3 (empty) or 1 and emits draw kind 0x0d subtype 1.

## Notes / uncertainty
Clip-gated text line: state byte 0x68e7e=1(drawn)/3(empty), emits kind0x0d sub1 only if gate open + non-empty. State value meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d95f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
