# 0x0060eff0 roomlist_query_fetch

| field | value |
|---|---|
| Original address | 0x0060eff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060eff0 |
| Resolved name | roomlist_query_fetch |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060ef20
**Callees:** FUN_0060eaa0, FUN_006157e0, FUN_006157e8, FUN_006159c0, FUN_006166f0
**Referenced globals:** ctx+0x19af4/0x19ae0/0x19ae8 (conn); ctx+0x197c0 (status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x197c0 status

## Behavioral explanation
Sends a query with a 4928-byte stack buffer (FUN_006159c0), spins the poll, stores status +0x197c0, restores mode (+0x19ae4), returns -1 iff status == -0xf.

## Notes / uncertainty
Blocking fetch into records@cursor+0x108 with 4928B scratch; restores saved mode; returns -1 iff status==-0xf (end-of-list). Record layout past +0x108 undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060eff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
