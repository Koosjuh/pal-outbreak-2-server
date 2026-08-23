# 0x005ef1a0 ui_input_state_init

| field | value |
|---|---|
| Original address | 0x005ef1a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef1a0 |
| Resolved name | ui_input_state_init |
| Subsystem | initialization |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e9490
**Callees:** —
**Referenced globals:** +0x2e4 UI state block (0x40c bytes); +0x4e8; +0x6ec; +0x6ee
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes a 0x40c-byte UI sub-state block at ctx+0x2e4 and seeds defaults (+0x4e8=0x100, +0x6ee=+0x6ec=0x1e).

## Notes / uncertainty
memset(ctx+0x2e4,0,0x40c) + defaults +0x4e8=0x100, +0x6ec=+0x6ee=0x1e. Field semantics inferred from values only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef1a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
