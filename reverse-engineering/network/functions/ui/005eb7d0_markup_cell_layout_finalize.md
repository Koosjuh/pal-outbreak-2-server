# 0x005eb7d0 markup_cell_layout_finalize

| field | value |
|---|---|
| Original address | 0x005eb7d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb7d0 |
| Resolved name | markup_cell_layout_finalize |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005eb640, FUN_005eb750, FUN_005f10a0
**Callees:** FUN_005ef640, FUN_005ef780, FUN_005efa60, FUN_005f00b0, FUN_005f0190, FUN_005f0300, FUN_005f0340, FUN_005f0a10
**Referenced globals:** +0xd894 (cell idx); +0x186 (mode); +0x18d (dirty); +0x24e0.. (cell struct); +0x2510/+0x2512/+0x2520 (col metrics); +0x42 (next-cell link); +0xf1c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd894; +0x186

## Behavioral explanation
Table-layout finalizer: marks dirty (+0x18d), runs sub-layout passes (FUN_005f0190/005f0300/005f0340), then walks the linked cell list via next-index +0x42 accumulating column widths into +0x2520 and commits (FUN_005ef640/005ef780).

## Notes / uncertainty
Box-model cell finalize; cell array +0x24e0 stride 0x5c, child walk via +0x42, container height accum +0x2520. Field names inferred; dense arithmetic. UI markup, not net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb7d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
