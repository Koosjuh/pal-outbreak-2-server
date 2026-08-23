# 0x005bec80 menu_build_label_0xaf

| field | value |
|---|---|
| Original address | 0x005bec80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bec80 |
| Resolved name | menu_build_label_0xaf |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bebf0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea70, FUN_005bea80
**Referenced globals:** 0x7018d0 menu UI object; 0x6cbe4a label string
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds lobby/room menu entry #0xaf into UI object 0x7018d0 from label string at 0x6cbe4a (strlen+setter).

## Notes / uncertainty
Menu-label builder: begin(0xAF)+append_string(0x6cbe4a,strlen)+commit+end on 0x7018d0. func_0x0010a050=strlen. Driven with siblings by group builder FUN_005bebf0. Builder callees inert this build; UI, not protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bec80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
