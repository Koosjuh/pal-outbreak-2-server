# 0x005e0390 frame_render_dispatch

| field | value |
|---|---|
| Original address | 0x005e0390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0390 |
| Resolved name | frame_render_dispatch |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8810
**Callees:** —
**Referenced globals:** 0x7010a0 (callback table); iRam00701098 (count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701098

## Behavioral explanation
Per-frame render setup: programs GS/render-state registers (func_0x001a7b70 id/val pairs) then invokes every registered draw callback in the 0x7010a0 table.

## Notes / uncertainty
Per-frame UI render top: kick batch (func_0x001a7440), program GS regs (func_0x001a7b70 id/val pairs), invoke all registered callbacks bracketed by render-mode reg 0x6c=0/1. Specific GS register ids/vals inferred, not named.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0390.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
