# 0x001a0eb0 asset_load_by_triplet

| field | value |
|---|---|
| Original address | 0x001a0eb0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a0eb0 |
| Resolved name | asset_load_by_triplet |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cfa30
**Callees:** FUN_001069a8, FUN_00109728, FUN_001841d0, FUN_001a0a50, FUN_001a0df0, FUN_001a79b0, FUN_001a7b70, FUN_001ab460, FUN_001cba30, FUN_001cbc20, FUN_001ce2d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Asset streaming loader keyed by 3 bytes: request via chanA, 0x50 reply header, per-block fetch(a0a50)->LZ decompress(a79b0)->GS upload(cba30) into parity slot band, build display structs (ce2d0), optional 2nd asset gated by hdr.off_1c with GS register batch. Graphics path, not lobby protocol. Header field/GS-helper meanings inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a0eb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
