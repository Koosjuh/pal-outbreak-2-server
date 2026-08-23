# 0x001aa780 reset_state_and_clear_flag_4fa64f

| field | value |
|---|---|
| Original address | 0x001aa780 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001aa780 |
| Resolved name | reset_state_and_clear_flag_4fa64f |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d0b00
**Callees:** FUN_001aa6c0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Calls FUN_001aa6c0(0) then clears byte 0x4fa64f. Reset-mode arg and flag meaning not traced.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001aa780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
