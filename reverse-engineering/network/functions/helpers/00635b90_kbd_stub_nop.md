# 0x00635b90 kbd_stub_nop

| field | value |
|---|---|
| Original address | 0x00635b90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635b90 |
| Resolved name | kbd_stub_nop |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty stub (immediate return); likely a stripped/unimplemented callback in the input path.

## Notes / uncertainty
8-byte empty function; reconstructed as an unimplemented widget hook slot. Purpose inferred from single caller cluster; no self-evidence, capped Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
