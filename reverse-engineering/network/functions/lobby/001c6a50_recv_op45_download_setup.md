# 0x001c6a50 recv_op45_download_setup

| field | value |
|---|---|
| Original address | 0x001c6a50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6a50 |
| Resolved name | recv_op45_download_setup |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001c3a60, FUN_001c3b10
**Referenced globals:** 0x35b7d0 total-len; 0x35b7e0 buffer; conn+0x48 offset; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x48 offset; conn+0xd next-state

## Behavioral explanation
Reply-0x45 handler: reads a total length (<0x100) into 0x35b7d0; if zero -> state 0x1d, else zeroes buffer 0x35b7e0, resets offset conn+0x48, advances to state 0x27 (chunk receive).

## Notes / uncertainty
Raised Medium→High. Machine-F setup: require sub-sel 1, total<0x100, zero buf 0x35b7e0, reset conn+0x48, state 0x27 (or 0x1d if empty). Cross-checked vs op47 handlers; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
