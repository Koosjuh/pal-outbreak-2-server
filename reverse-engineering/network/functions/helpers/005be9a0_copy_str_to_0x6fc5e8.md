# 0x005be9a0 copy_str_to_0x6fc5e8

| field | value |
|---|---|
| Original address | 0x005be9a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be9a0 |
| Resolved name | copy_str_to_0x6fc5e8 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890, FUN_005ad9f0, FUN_005ada90, FUN_005ae0b0, FUN_005b53b0, FUN_005b5710, FUN_005b5760, FUN_005b59b0, FUN_005b5a00, FUN_005b5a50, FUN_005b6030, FUN_005b6070, FUN_005b67b0, FUN_005b6860, FUN_005f7b30, FUN_005fc0c0, FUN_005fc2b0, FUN_005fc7c0, FUN_006014c0, FUN_00618090, FUN_0062b2c0, FUN_0062cba0, FUN_0062cc60, FUN_0062e9b0, FUN_0062ec90, FUN_0062edc0, FUN_0062f060
**Callees:** —
**Referenced globals:** 0x6fc5e8 dest buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies/formats the caller's data into global buffer 0x6fc5e8 (func_0x00109eb8, a string/mem copy).

## Notes / uncertainty
strcpy into shared 0x300-byte event/message buffer 0x6fc5e8 (27 callers); generic staging primitive, unbounded copy. Buffer role from GLOBALS tag, not a live trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be9a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
