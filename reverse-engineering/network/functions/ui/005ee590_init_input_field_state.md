# 0x005ee590 init_input_field_state

| field | value |
|---|---|
| Original address | 0x005ee590 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee590 |
| Resolved name | init_input_field_state |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8d30, FUN_005e8d60
**Callees:** —
**Referenced globals:** iRam007012a0; +0xdf6/+0xdf8 (metrics); +0xaf6/+0xbf6/+0xcf6 (field bufs)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes input-field render state: sets default metrics +0xdf6/+0xdf8=0x1e and zeroes the three 0x100-byte field buffers +0xaf6/+0xbf6/+0xcf6.

## Notes / uncertainty
Sets field metrics +0xdf6/+0xdf8=0x1e, memsets three 0x100 buffers af6/bf6/cf6. Buffer name/value/id labels inferred from consumers. Unambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
