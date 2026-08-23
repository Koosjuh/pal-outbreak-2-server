# 0x005bda30 read_local_id_record

| field | value |
|---|---|
| Original address | 0x005bda30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bda30 |
| Resolved name | read_local_id_record |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b6070
**Callees:** —
**Referenced globals:** 0x6cd66c/6cd66e/6cd670 6-byte id record
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a 6-byte (3-short) record from globals 0x6cd66c/6e/70 into the caller's buffer (likely a local id/MAC/name triple).

## Notes / uncertainty
Copies 3 u16 (6 bytes) from 0x6cd66c/6e/70 (caller FUN_005b6070 case4). MAC/short-id-triple interpretation inferred, not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bda30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
