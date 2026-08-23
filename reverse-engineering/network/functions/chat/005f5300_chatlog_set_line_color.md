# 0x005f5300 chatlog_set_line_color

| field | value |
|---|---|
| Original address | 0x005f5300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5300 |
| Resolved name | chatlog_set_line_color |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f54d0
**Callees:** FUN_005af2c0
**Referenced globals:** iRam003435d4+0xc8000(ring); 0x649710(color LUT); 0x24eba9(sender-flag table); cRam006c50fb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c50fb

## Behavioral explanation
Selects the text color for a log line (sender name / body / header) from a per-sender flag, via a color table.

## Notes / uncertainty
Sets palette index for chat field 0/1/2 via FUN_005af2c0. Digit tag '0'-'7' (char-class table 0x24eba9 bit 0x04) -> per-slot color LUT 0x649710[(c-0x30)&7]; else defaults 0x10/0x11/0x15/0x00/0x14 by field & log-mode. Name-self compare vs string 0x6c69cc. LUT byte values and 0x6c69cc identity not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
