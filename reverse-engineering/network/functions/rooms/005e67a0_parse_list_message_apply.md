# 0x005e67a0 parse_list_message_apply

| field | value |
|---|---|
| Original address | 0x005e67a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e67a0 |
| Resolved name | parse_list_message_apply |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7070
**Callees:** FUN_005d9e30, FUN_005d9ea0, FUN_005e5e50, FUN_005e6630
**Referenced globals:** iRam007012a0+0xd964 (cursor), +0x191/+0x192 (screen/refresh state), +0x186; 0x874500 (entry table, case 4 clears 0xa28), bRam008744f8 (result/error byte); 0x6481a8/0x6481b0 (tag match strings)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x191; iRam007012a0+0x192; bRam008744f8

## Behavioral explanation
Applies a parsed lobby LIST/screen message: switch on message id (1-7) reads a sequence of quoted tokens (FUN_005e5e50) and dispatches each field to the state-applier FUN_005d9ea0 with field ids, building room/user lists of up to 10 entries.

## Notes / uncertainty
Text/markup LIST applier; switch on msg-template id (1/2/4/5/6/7) reads quoted tokens (0=value,nonzero=tag/EOF) into typed UI slots via ui_store_label_text. Case 4 builds a 10-row list and writes the entry count to bRam008744f8 (=0x8744f8 room/list count). Per-field-id -> UI column mapping (7/0xc/0xd/8/9/10) not proven; whether template 4 is room-list vs member-list depends on caller FUN_005e7070.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e67a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
