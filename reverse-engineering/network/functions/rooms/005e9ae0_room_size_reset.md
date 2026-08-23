# 0x005e9ae0 room_size_reset

| field | value |
|---|---|
| Original address | 0x005e9ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9ae0 |
| Resolved name | room_size_reset |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef0e0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x8f2 (max); cfg+0x8f4 (count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x8f2; cfg+0x8f4

## Behavioral explanation
Applies arg, sets max cfg+0x8f2=4 and count cfg+0x8f4=0 (no redraw call).

## Notes / uncertainty
No-redraw variant of 0x9a90: seeds max=4/count=0 only. Which markup element binds each variant unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9ae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
