# 0x005b5f60 room_sel_apply_2u16_to_screen

| field | value |
|---|---|
| Original address | 0x005b5f60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5f60 |
| Resolved name | room_sel_apply_2u16_to_screen |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00, FUN_005c2890
**Referenced globals:** cRam006c4b90 (mode); 0x6c4fe6/0x6c4fe8 (selection output fields)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90

## Behavioral explanation
In room modes 4/0x0e: read selected index and apply FUN_005c2890 writing to fields 0x6c4fe6/0x6c4fe8.

## Notes / uncertainty
Screen-gated (screen_id 0x04/0x0e room screens only): copies trailing 2x u16 (src 0x6cfa2c/2e) into scalar globals 0x6c4fe6/0x6c4fe8; callee guards idx!=0. Meaning of the two words unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5f60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
