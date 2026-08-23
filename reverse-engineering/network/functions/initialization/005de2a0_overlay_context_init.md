# 0x005de2a0 overlay_context_init

| field | value |
|---|---|
| Original address | 0x005de2a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de2a0 |
| Resolved name | overlay_context_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae260, FUN_005f3e30, FUN_005f4040, FUN_006076c0, FUN_00608300, FUN_006088b0, FUN_00624c70
**Callees:** —
**Referenced globals:** iRam00701068 (context base); iRam00701070/78/88 (sub-region ptrs); uRam00701080=0x8710e0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068

## Behavioral explanation
Initializes the overlay/browser context arena: stores base in iRam00701068, zeroes 0x6a000 bytes and seeds sub-region pointers (+0x4f980/+0x4ff48/+0x60bc4) and uRam00701080.

## Notes / uncertainty
Already reconstructed; verified base bind + 0x6a000 memset + 3 sub-region seeds. Role of const 0x8710e0 and sub-region contents inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de2a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
