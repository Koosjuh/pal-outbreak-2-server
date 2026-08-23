# 0x005ef0e0 render_text_token_flush_if_pending

| field | value |
|---|---|
| Original address | 0x005ef0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef0e0 |
| Resolved name | render_text_token_flush_if_pending |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8750, FUN_005e8810, FUN_005e8990, FUN_005e89f0, FUN_005e8ad0, FUN_005e8b40, FUN_005e8ca0, FUN_005e9380, FUN_005e9a90, FUN_005e9ae0, FUN_005e9b20, FUN_005ea820, FUN_005ea880, FUN_005ebd20
**Callees:** FUN_005ec170, FUN_005eea60, FUN_005eeca0, FUN_005eed40, FUN_005f3cc0
**Referenced globals:** 0x007012a0 UI-ctx base (iRam007012a0); +0xd892 node-stack depth; +0x188 root-node idx; +0x1540 root-node array; +0xd8bc layout cursor; +0x4 active-op field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892 node-stack depth; +0xd8bc

## Behavioral explanation
UI-tree teardown/reset entry: when node-stack empty, finalizes the root layout node (measure/emit/close) then clears context+0x4 and the caller's active flag.

## Notes / uncertainty
Third flush variant; finalize_run_metrics guarded by cursor-x (+0xd8bc)!=0 (only close a pending run). Renamed from ui_dialog_close_reset (was a misleading guess). Delegates 0x5f3cc0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef0e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
