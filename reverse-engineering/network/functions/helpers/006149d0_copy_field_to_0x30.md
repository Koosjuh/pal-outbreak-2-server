# 0x006149d0 copy_field_to_0x30

| field | value |
|---|---|
| Original address | 0x006149d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006149d0 |
| Resolved name | copy_field_to_0x30 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** —
**Referenced globals:** iRam0070d1c0+0x30
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x30

## Behavioral explanation
Copies dword *(param_1+0x18) into overlay state iRam+0x30.

## Notes / uncertainty
Copies src[+0x18] into UI state +0x30; meaning of both offsets needs FUN_0060f910 decode. Held Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006149d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
