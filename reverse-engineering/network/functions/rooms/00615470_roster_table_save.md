# 0x00615470 roster_table_save

| field | value |
|---|---|
| Original address | 0x00615470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615470 |
| Resolved name | roster_table_save |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** —
**Referenced globals:** iRam0070d1c0+0xed0 (src); 0x3c9594 (dest)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0xed0

## Behavioral explanation
Copies the 65x8B table from iRam+0xed0 into 0x3c9594 (save/backup).

## Notes / uncertainty
Unrolled 65x8B (0x208) memcpy from iRam0070d1c0+0xed0 to fixed 0x3c9594 backup. Entry semantics (what the 8B holds) and the paired restore fn not decoded; direction implies 'save'.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
