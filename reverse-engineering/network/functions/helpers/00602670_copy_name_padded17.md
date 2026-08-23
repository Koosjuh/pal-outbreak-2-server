# 0x00602670 copy_name_padded17

| field | value |
|---|---|
| Original address | 0x00602670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00602670 |
| Resolved name | copy_name_padded17 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00602700
**Callees:** —
**Referenced globals:** 0x70b420 fixed-width name scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a string into fixed scratch buffer 0x70b420, pre-filled with 0x11 spaces at +0x20, for fixed-width name column rendering.

## Notes / uncertainty
Formats name into 17-space-padded scratch 0x70b420 then strcpy-overwrites. CORRECTED prior record: spaces are at base (memset val=0x20), not +0x20. No length clamp to 17.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00602670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
