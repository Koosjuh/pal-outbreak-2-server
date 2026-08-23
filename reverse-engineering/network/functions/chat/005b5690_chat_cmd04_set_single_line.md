# 0x005b5690 chat_cmd04_set_single_line

| field | value |
|---|---|
| Original address | 0x005b5690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5690 |
| Resolved name | chat_cmd04_set_single_line |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c3e80
**Referenced globals:** 0x6c9d32 chat/message buffer (0x31c); 0x6c9d33/0x6c9d44 sender/text fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c9d32 ready flag

## Behavioral explanation
Registered command handler (selector id 4): clears the 0x31c-byte chat/message buffer at 0x6c9d32, parses one record (0x5c3e80), and sets its ready flag.

## Notes / uncertainty
Command-selector-4: clears single-line block 0x6c9d32 (0x31c), parses via same 0x5c3e80 into name@+1/text@+0x12, sets ready flag. Single-slot replace counterpart to scrollback append. Banner vs whisper semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
