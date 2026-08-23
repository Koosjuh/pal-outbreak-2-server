# 0x001ed664 pktbuf_get_f28

| field | value |
|---|---|
| Original address | 0x001ed664 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed664 |
| Resolved name | pktbuf_get_f28 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e1c10
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x28

## Behavioral explanation
Getter: returns field buf+0x28 (an id/channel compared in FUN_001edfd0).

## Notes / uncertainty
Getter for +0x28 identity/tag word (match key used by f28_eq). Field meaning channel/conn/msg-id inferred, not runtime-confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed664.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
