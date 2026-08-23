# 0x001c6c60 recv_op47_download_chunk

| field | value |
|---|---|
| Original address | 0x001c6c60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6c60 |
| Resolved name | recv_op47_download_chunk |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3a60, FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x35b7d0 total; 0x35b7e0 buffer; conn+0x48 offset; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x47
**State vars:** conn+0x48 offset; conn+0xd

## Behavioral explanation
Reply-0x47 handler: reads offset+len, if within 0x35b7d0/0x100 stores new cursor at conn+0x48 and stays state 0x27 else state 0x1d, copies body into 0x35b7e0+offset.

## Notes / uncertainty
Machine-F reply: require sub-sel 1, copy into 0x35b7e0+base, advance conn+0x48; continue 0x27 while new<total&&<0x100 else complete 0x1d. runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6c60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
