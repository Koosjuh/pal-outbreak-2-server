# 0x005bd830 get_local_name_6cc440

| field | value |
|---|---|
| Original address | 0x005bd830 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd830 |
| Resolved name | get_local_name_6cc440 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b6070
**Callees:** —
**Referenced globals:** 0x6cc440 (local name)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies the local name string at 0x6cc440 into the caller's buffer.

## Notes / uncertainty
strcpy of local player NAME from 0x6cc440; caller FUN_005b6070 case2 stages it 0x10 bytes into identity block 0x874fb0 for registration. name-vs-id split inferred from caller field widths.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd830.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
