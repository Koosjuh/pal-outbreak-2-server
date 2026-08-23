# 0x0062dc40 create_room_flow

| field | value |
|---|---|
| Original address | 0x0062dc40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062dc40 |
| Resolved name | create_room_flow |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d950
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005bd940, FUN_005bff20, FUN_005c04f0, FUN_005c0750, FUN_005c28f0, FUN_005fb670, FUN_0062e8e0
**Referenced globals:** 0x6c4b9c room param; 0x6c4b94 selected char slot; 0x343625 config; struct+0x1e50 create-record(0xd4); struct+0x42b screen-id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x10 create-step; struct+0x42b screen(0xd/0x11/0x14/0x9); struct+0x9a4 timer; struct+0x9a9 result

## Behavioral explanation
Create-room state machine (struct+0x10 switch): builds a 0xd4-byte room-create record at +0x1e50 (fills char stats from sRam006c4b94, uRam006c4b9c, bRam00343625) and sends via FUN_005bd940(...,0x62eb70); later steps register replies 0x62ec90/0x62ed30/0x62edc0.

## Notes / uncertainty
Already fully reconstructed. Create-room SM (step +0x10); step0 builds+sends 0xd4 create record via FUN_005bd940, step4 consumes result byte +0x9a9 and enters via FUN_0062e8e0. Open: exact framing opcode (op04 vs transport op26) and full 0xd4 record layout beyond +0xc8..+0xce.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062dc40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
