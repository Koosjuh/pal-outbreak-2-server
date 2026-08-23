# 0x005fe8d0 roomlist_screen_init_and_ingest_sm

| field | value |
|---|---|
| Original address | 0x005fe8d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe8d0 |
| Resolved name | roomlist_screen_init_and_ingest_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005b8cf0, FUN_005b9110, FUN_005bffa0, FUN_005c0250, FUN_005c02b0, FUN_005c0850, FUN_005c0960, FUN_005c0a00, FUN_005c0f20, FUN_005c0f60, FUN_005c2820
**Referenced globals:** 0x6c0760 per-entry table (0x15c stride); 0x6970a0 parsed-list dest; 0x6970f4 entry count; 0x6970f6 name buffers; 0x6c0778 selection field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x10 step; param_1+0x16 timer; param_1+0x97d ready-flag; param_1+0x42b screen-id

## Behavioral explanation
Menu screen init/step-machine that registers the field-sync decoder callbacks and, in case 5, parses a server list (count byte, per-entry 0x14a8 stride, inner name loop of 0x41 stride) into the 0x6970xx room/area tables.

## Notes / uncertainty
7-case screen SM: seeds 30-slot room table 0x6c0760 (0x28c8), registers 7 field decoders, sends sel 0x76, timer-waits, ingests count-prefixed per-entry records (0x14a8 stride, nested 0x41 name list) into 0x6970xx, finalizes. FUN_005adc80(2)=room ordinal and the 0x76 selector are inferred; parsed_list layout reconstructed from copy offsets.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
