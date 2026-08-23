# 0x005f10a0 ui_node_process_dispatch

| field | value |
|---|---|
| Original address | 0x005f10a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f10a0 |
| Resolved name | ui_node_process_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005eacd0, FUN_005eb3f0, FUN_005ebd20
**Callees:** FUN_005eacd0, FUN_005eb250, FUN_005eb3f0, FUN_005eb7d0, FUN_005ebd20, FUN_005ef5b0, FUN_005ef5e0, FUN_005ef850, FUN_005f08c0, FUN_005f0930
**Referenced globals:** +0xd892/+0xd894/+0xd89a node stack; +0x24fb subtype, +0x24ec child ptr, +0x1b type, +0x252e valid
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x24fb

## Behavioral explanation
Larger per-node processing dispatcher: by pass-arg and node subtype (+0x24fb / +0x1b) opens containers, runs group/row-span expansion, and finalizes rows/cells across the three layout passes.

## Notes / uncertainty
Heavier finish-time reconciler; mutually recursive with eacd0/eb3f0/ebd20; runs group expander f08c0/f0930 (colspan/rowspan). Group find/expand named by role, not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f10a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
