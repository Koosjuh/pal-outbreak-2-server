# 0x001d507c snap_conn_reset_seq_state

| field | value |
|---|---|
| Original address | 0x001d507c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d507c |
| Resolved name | snap_conn_reset_seq_state |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6ee0, FUN_001d9550, FUN_001d9678, FUN_001d9b6c, FUN_001d9f78, FUN_001db7e8
**Callees:** FUN_001069a8, FUN_001e234c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x48 substate=2; conn+0x4a seq; conn+0x58/0x5c seq heads

## Behavioral explanation
Resets a connection's sequence/window state: stores peer id at +0x4c, zeroes send cursor +0xc, clears the two seq-head cells, seeds the seq at +0x4a, and sets state field +0x48=2.

## Notes / uncertainty
Resets reliable window: conn+0x4c peer-id, zeroes send cursor conn+0xc and both seq-head pointers (**+0x58/**+0x5c), htons seq seed at +0x4a, sets substate +0x48=2. Two guards allow full/peer-only/seed-only use.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d507c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
