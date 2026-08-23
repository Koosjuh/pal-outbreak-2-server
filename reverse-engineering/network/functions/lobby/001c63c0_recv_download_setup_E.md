# 0x001c63c0 recv_download_setup_E

| field | value |
|---|---|
| Original address | 0x001c63c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c63c0 |
| Resolved name | recv_download_setup_E |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10
**Referenced globals:** 0x365bb0 count; 0x365bf4 ptrs; 0x365bb4 ids; 0x365bd4 sizes; 0x35ccb8 ring; 0x365c14/0x365c18 seq; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x365c14/0x365c18 seq; conn+0xd=0x41

## Behavioral explanation
Reply handler: reads count (clamped 8) into 0x365bb0, fills dest ptrs (0x365bf4 into ring 0x35ccb8, 0x200 stride) plus id(0x365bb4)+size(0x365bd4) pairs, resets seq, advances to state 0x41.

## Notes / uncertainty
Raised Medium→High. Machine-E manifest: count (clamp 8) + (id,size) pairs, dest ring 0x35ccb8 stride 0x200, state 0x41 (or 0x31 if count 0). Cross-checked vs E fetch/reply handlers; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c63c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
