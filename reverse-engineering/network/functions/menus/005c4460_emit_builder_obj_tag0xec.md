# 0x005c4460 emit_builder_obj_tag0xec

| field | value |
|---|---|
| Original address | 0x005c4460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4460 |
| Resolved name | emit_builder_obj_tag0xec |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ae630
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea80
**Referenced globals:** 0x7018d0 (UI/handler object block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers/initializes a UI handler object (id 0xec) at 0x7018d0 via the be9e0/bea10/bea80 triad.

## Notes / uncertainty
Renamed from register_ui_obj_0xec: begin(0xec)/commit/finalize builder triad into 0x7018d0, no payload. Builder role inferred (be9e0/bea10/bea80 bodies unread).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
