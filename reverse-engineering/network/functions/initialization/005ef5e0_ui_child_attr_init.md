# 0x005ef5e0 ui_child_attr_init

| field | value |
|---|---|
| Original address | 0x005ef5e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef5e0 |
| Resolved name | ui_child_attr_init |
| Subsystem | initialization |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb5a0, FUN_005eb640, FUN_005eb6f0, FUN_005eb750, FUN_005f0930, FUN_005f10a0
**Callees:** —
**Referenced globals:** +0xf10 child-attr block (0x10c bytes); +0xf18; +0x18a/+0x18c flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x18a; +0x18c

## Behavioral explanation
Zeroes a 0x10c-byte child-attr block at ctx+0xf10 and resets +0xf18=0xffffffff plus flags +0x18a/+0x18c.

## Notes / uncertainty
Full reset of child-attr block memset(ctx+0xf10,0,0x10c) + +0xf18=0xffffffff + flags +0x18a/+0x18c=0. Superset of ui_align_state_clear. Flag meanings unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef5e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
