# 0x005da780 ui_compute_margins

| field | value |
|---|---|
| Original address | 0x005da780 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da780 |
| Resolved name | ui_compute_margins |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c80a0, FUN_005da370
**Callees:** —
**Referenced globals:** iRam00701070+0x1a..0x20: margins; iRam00701070+0x18: flag word; iRam00701068+0x68e81
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x18; 0x1a; 0x1c; 0x1e; 0x20

## Behavioral explanation
UI geometry: sets viewport margin words +0x1a/+0x1c/+0x1e/+0x20 based on the +0x18 flag bits and two mode chars; sets attention flag 0x68e81 in one branch.

## Notes / uncertainty
Computes 4 inset margins from border_char + style bits 0x01/0x02/0x04; sets attention flag 0x68e81. Slot-to-edge mapping and bit names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
