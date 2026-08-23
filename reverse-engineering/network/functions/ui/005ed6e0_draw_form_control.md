# 0x005ed6e0 draw_form_control

| field | value |
|---|---|
| Original address | 0x005ed6e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed6e0 |
| Resolved name | draw_form_control |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005edc40, FUN_005f2940
**Callees:** FUN_005d8d60, FUN_005d8e00, FUN_005d8ea0, FUN_005d9030, FUN_005d9160, FUN_005d9450, FUN_005d9520, FUN_005d9dd0, FUN_005ed530, FUN_005ed630
**Referenced globals:** iRam007012a0; +0x4e4 (control type); +0x2e4/+0x3e4 (label/value bufs); +0x188 (line idx); +0x186 (pass)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4e4; +0x186

## Behavioral explanation
Renders a form control by type (+0x4e4 switch 0..7): checkbox/radio/button/image/etc., wrapping the line then dispatching to draw primitives FUN_005d9030/9160/8d60/8e00/9450/9520/9dd0/8ea0.

## Notes / uncertainty
8-arm switch on ctrl_type(+0x4e4) reserving cell + dispatching to FUN_005d9xxx draw primitives; draw gated pass==0 && suppress==0. Widget semantics of each primitive inferred, not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed6e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
