# 0x005c7e30 set_status_message_by_code

| field | value |
|---|---|
| Original address | 0x005c7e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7e30 |
| Resolved name | set_status_message_by_code |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bc2a0, FUN_005bc2f0, FUN_005bc590, FUN_005bc990, FUN_005bca90, FUN_005bcfd0, FUN_005be330, FUN_005bfb40, FUN_005c05c0, FUN_005c21c0, FUN_005c7d40
**Callees:** FUN_005c7ff0
**Referenced globals:** 0x6fc5e8 (status/message buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Clears the status/message buffer (0x6fc5e8, 0x300) then maps a status code (0..0xe) to a table index and copies the localized string in.

## Notes / uncertainty
memset(0x6fc5e8,0,0x300) then code(0..0xe)->stridx remap -> lookup_localized_string -> strcpy. Exact code->index map captured; localized text and per-code domain meaning external.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
