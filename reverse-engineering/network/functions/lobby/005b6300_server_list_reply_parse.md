# 0x005b6300 server_list_reply_parse

| field | value |
|---|---|
| Original address | 0x005b6300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6300 |
| Resolved name | server_list_reply_parse |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618890
**Referenced globals:** cRam006c4b90 (mode); 0x697020 (parsed entry table, 0xc stride); 0x6c5480 (name-ptr table); uRam003435d4 (buffer base); uRam006c4ba0/cRam006c4b9f (menu step)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4b9f

## Behavioral explanation
On result byte 0: parse a count+entry list (FUN_00618890) of 12-byte records into table 0x697020, clear a 0x8000 buffer, populate name pointers from 0x6c5480, advance menu step; on 0xFF just advance step.

## Notes / uncertainty
List-reply ingestion: result byte 0=parse count+12B records (3×u32) into 0x697020, clear 0x8000 name buf, populate name ptrs, advance menu step; 0xFF=advance only. Second (name-copy) loop reads fixed record-0 globals as memcpy src/len — likely lost-index decompiler artifact (intended per-entry); flagged. Record field meanings inferred; Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
