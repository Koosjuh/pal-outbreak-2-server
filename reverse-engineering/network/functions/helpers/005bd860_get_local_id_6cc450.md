# 0x005bd860 get_local_id_6cc450

| field | value |
|---|---|
| Original address | 0x005bd860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd860 |
| Resolved name | get_local_id_6cc450 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b6070
**Callees:** —
**Referenced globals:** 0x6cc450 (local id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies the local id string at 0x6cc450 into the caller's buffer.

## Notes / uncertainty
strcpy of local player ID from 0x6cc450; caller stages 0x11 bytes into 0x874fc0. Could be fixed 0x11 handle rather than string.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
