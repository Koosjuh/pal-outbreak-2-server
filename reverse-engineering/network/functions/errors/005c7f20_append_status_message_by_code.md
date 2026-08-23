# 0x005c7f20 append_status_message_by_code

| field | value |
|---|---|
| Original address | 0x005c7f20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7f20 |
| Resolved name | append_status_message_by_code |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bc990, FUN_005bca90, FUN_005bcfd0
**Callees:** FUN_005c7ff0
**Referenced globals:** 0x6fc5e8 (status/message buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Same code->string map as FUN_005c7e30 but appends (func_0x00109ab0) to the status buffer instead of overwriting.

## Notes / uncertainty
Append twin of 005c7e30 (no memset; strcat thunk 00109ab0 vs strcpy 00109eb8). Same remap table. Bounds behavior of strcat on 0x300 buf unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7f20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
