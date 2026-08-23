# 0x005b25c0 lobby_init_and_register_handlers

| field | value |
|---|---|
| Original address | 0x005b25c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b25c0 |
| Resolved name | lobby_init_and_register_handlers |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af2f0, FUN_005af310, FUN_005b68e0, FUN_005b6900, FUN_005b6950, FUN_005b8cf0, FUN_005ba7b0, FUN_005bb440, FUN_005bd2e0, FUN_005bd6e0, FUN_005bdf70, FUN_005f4b70, FUN_00618b60
**Referenced globals:** 0x702140 uStack_30 handle; 0x8710f1 / 0x8710e0 id blobs; 0x245e38 config string; 0x343571 cRam00343571 option flag
**Referenced strings:** 0x8710f1; 0x8710e0; 0x245e38
**Referenced opcodes:** 0x09
**State vars:** struct+0x550; struct+0x45a ready

## Behavioral explanation
Screen-0 init: zeroes lobby buffers and registers ~30 command/selector handlers via 0x5bdf70, then builds+submits the session USER registration struct.

## Notes / uncertainty
Login/init screen SM: registers ~30 selector->handler entries (full id->fnptr table captured), submits op09 USER register (5bd6e0, MAC/console id via 001bf2e0), then step-2 submits a login req with completion cb 0x5b6070. Wire layouts of the two structs partly inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b25c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
