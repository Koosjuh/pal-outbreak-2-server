# 0x005bb380 render_message_lines

| field | value |
|---|---|
| Original address | 0x005bb380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb380 |
| Resolved name | render_message_lines |
| Subsystem | chat |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b9150
**Callees:** FUN_005af2c0, FUN_005af2e0, FUN_005bb1f0, FUN_005bb270, FUN_0062fd30
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates a display-descriptor list (stride 0xc) from FUN_0062fd30, positioning each line with FUN_005bb1f0(+3) and drawing it centered via FUN_005bb270 until the terminator (+0 != 0).

## Notes / uncertainty
Walks descriptor list (FUN_0062fd30, stride 0xc: +0 last-flag,+3 kind,+6 y,+8 text*), centers each line ((640-10*w)/2), draws via 005bb1f0/005bb270; terminator inclusive. Layout certain; +6 as Y inferred from callee signature.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
