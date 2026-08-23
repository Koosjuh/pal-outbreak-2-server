# 0x001ed60c pktbuf_get_f24

| field | value |
|---|---|
| Original address | 0x001ed60c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed60c |
| Resolved name | pktbuf_get_f24 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d5ae4, FUN_001d63b8, FUN_001d6468
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x24

## Behavioral explanation
Getter: returns field buf+0x24.

## Notes / uncertainty
Getter +0x24; called by reliable build/send fns (FUN_001d5ae4/63b8/6468) but no setter indexed and no arithmetic pins its role -> highest-uncertainty field; 'control/flags word' is placeholder inference. Getter behavior itself certain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed60c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
