# 0x005bdc30 snapshot_0x6cc668_table

| field | value |
|---|---|
| Original address | 0x005bdc30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdc30 |
| Resolved name | snapshot_0x6cc668_table |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3590
**Callees:** —
**Referenced globals:** 0x6cc668 table source
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swap-copies the 0x802-short table at 0x6cc668 out into the caller's buffer (state snapshot/export).

## Notes / uncertainty
Exports 0x1004-byte state table 0x6cc668 to caller buffer (inverse of init copy, same caller FUN_005b3590); plain copy not byte-swap. Save vs transmit use undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdc30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
