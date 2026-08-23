# 0x005f0e10 ui_node_edge_dispatch

| field | value |
|---|---|
| Original address | 0x005f0e10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0e10 |
| Resolved name | ui_node_edge_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ea820, FUN_005ea880, FUN_005eb0f0, FUN_005eb1d0, FUN_005eb5a0, FUN_005eb640, FUN_005eb6f0, FUN_005eb750
**Callees:** FUN_005ea900, FUN_005eacd0, FUN_005eb250, FUN_005eb3f0, FUN_005ebd20, FUN_005ef550, FUN_005ef5b0, FUN_005ef850
**Referenced globals:** +0xd892 depth; +0xd894 current node; +0xd89a stack; +0x24fb node subtype, +0x252e valid flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x24fb

## Behavioral explanation
Dispatches a layout node by pass-arg (1..4) and node subtype (+0x24fb): pushes a fresh node when stack empty, then routes to container-open/row/cell handlers (ea900/eb250/eb3f0/ebd20/eacd0).

## Notes / uncertainty
Implicit open/close reconciler (param_3=edge class 1..4) keeping the table grammar well-formed. Which source tag maps to each edge class is inferred from open/close pairing, not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0e10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
