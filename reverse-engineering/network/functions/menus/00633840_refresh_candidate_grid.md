# 0x00633840 refresh_candidate_grid

| field | value |
|---|---|
| Original address | 0x00633840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633840 |
| Resolved name | refresh_candidate_grid |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631d60, FUN_00633470
**Callees:** FUN_00633590, FUN_006335f0, FUN_00633650
**Referenced globals:** 0x715da8+0x24c; 0x715da8+0x250; 0x715da8+0x258 (count); 0x7158f0; 0x715b30
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x24c

## Behavioral explanation
Rebuilds the on-screen 3-cell candidate grid from the current count (state+0x258), resetting cursor (+0x24c/+0x250).

## Notes / uncertainty
IME candidate-grid rebuild; gated by +0x36, resets cursor/page, clears table 0x7158f0 + cells 0x715b30, populates visible 3-window. FUN_006335f0 register-returned loop bounds (t0/t1) not fully decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
